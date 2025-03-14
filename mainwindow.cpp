#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_audioManager(new AudioManager(this))
    , m_backgroundManager(new BackgroundManager(this))
{
    ui->setupUi(this);
    this->setFixedSize(800, 450);
    this->setWindowTitle("sky-piano");
    this->setWindowIcon(QIcon(":/icons/icon.png"));
    
    setupPianoKeys();
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupPianoKeys()
{
    // 定义钢琴键的配置
    struct KeyConfig {
        int number;
        Qt::Key key;
        QPushButton* button;
    };

    KeyConfig configs[] = {
        {1, Qt::Key_Q, ui->b1}, {2, Qt::Key_W, ui->b2},
        {3, Qt::Key_E, ui->b3}, {4, Qt::Key_R, ui->b4},
        {5, Qt::Key_T, ui->b5}, {6, Qt::Key_A, ui->b6},
        {7, Qt::Key_S, ui->b7}, {8, Qt::Key_D, ui->b8},
        {9, Qt::Key_F, ui->b9}, {10, Qt::Key_G, ui->b10},
        {11, Qt::Key_Z, ui->b11}, {12, Qt::Key_X, ui->b12},
        {13, Qt::Key_C, ui->b13}, {14, Qt::Key_V, ui->b14},
        {15, Qt::Key_B, ui->b15}
    };

    for (const auto& config : configs) {
        QString soundFile = QString(":/sounds/%1.mp3").arg(config.number);
        auto key = new PianoKey(config.number, config.key, soundFile, this);
        m_pianoKeys[config.number] = key;
        
        connect(config.button, &QPushButton::clicked, key, [key]() {
            key->setPressed(true);
            // 使用QTimer来模拟按钮释放
            QTimer::singleShot(100, key, [key]() {
                key->setPressed(false);
            });
        });
    }
}

void MainWindow::setupConnections()
{
    // 连接钢琴键信号
    for (auto key : m_pianoKeys) {
        connect(key, &PianoKey::keyStateChanged,
                this, &MainWindow::onKeyStateChanged);
        connect(key, &PianoKey::playRequested,
                m_audioManager, &AudioManager::playSound);
    }

    // 连接背景相关信号
    connect(m_backgroundManager, &BackgroundManager::backgroundChanged,
            this, &MainWindow::onBackgroundChanged);
    connect(ui->actionset_background, &QAction::triggered,
            this, &MainWindow::selectBackground);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) return;
    
    for (auto key : m_pianoKeys) {
        if (key->keyboardKey() == static_cast<Qt::Key>(event->key())) {
            key->setPressed(true);
            break;
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) return;

    for (auto key : m_pianoKeys) {
        if (key->keyboardKey() == static_cast<Qt::Key>(event->key())) {
            key->setPressed(false);
            break;
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    const QPixmap& background = m_backgroundManager->currentBackground();
    
    if (!background.isNull()) {
        painter.drawPixmap(rect(), background);
    }
    
    QMainWindow::paintEvent(event);
}

void MainWindow::onKeyStateChanged(int keyNumber, bool pressed)
{
    if (QPushButton* button = getButtonForKey(keyNumber)) {
        button->setDown(pressed);
    }
}

void MainWindow::onBackgroundChanged()
{
    update();
}

void MainWindow::selectBackground()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select background image"),
        "",
        tr("图片文件 (*.png *.jpg *.jpeg *.bmp)"));
        
    if (!fileName.isEmpty()) {
        m_backgroundManager->setBackgroundFromFile(fileName);
    }
}

QPushButton* MainWindow::getButtonForKey(int keyNumber)
{
    switch(keyNumber) {
        case 1: return ui->b1;
        case 2: return ui->b2;
        case 3: return ui->b3;
        case 4: return ui->b4;
        case 5: return ui->b5;
        case 6: return ui->b6;
        case 7: return ui->b7;
        case 8: return ui->b8;
        case 9: return ui->b9;
        case 10: return ui->b10;
        case 11: return ui->b11;
        case 12: return ui->b12;
        case 13: return ui->b13;
        case 14: return ui->b14;
        case 15: return ui->b15;
        default: return nullptr;
    }
}
