#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QtMultimedia/QMediaPlayer>
#include <QDebug>
#include <QFileInfo>
#include <QAudioOutput>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 450);
    
    for(int i = 0; i < 15; i++) {
        QMediaPlayer *player = new QMediaPlayer(this);
        QAudioOutput *audioOutput = new QAudioOutput(this);
        player->setAudioOutput(audioOutput);
        audioOutput->setVolume(1.0);
        
        players.append(player);
        audioOutputs.append(audioOutput);
    }

    connect(ui->b1, &QPushButton::clicked, this, [this](){ playSound(1); });
    connect(ui->b2, &QPushButton::clicked, this, [this](){ playSound(2); });
    connect(ui->b3, &QPushButton::clicked, this, [this](){ playSound(3); });
    connect(ui->b4, &QPushButton::clicked, this, [this](){ playSound(4); });
    connect(ui->b5, &QPushButton::clicked, this, [this](){ playSound(5); });
    connect(ui->b6, &QPushButton::clicked, this, [this](){ playSound(6); });
    connect(ui->b7, &QPushButton::clicked, this, [this](){ playSound(7); });
    connect(ui->b8, &QPushButton::clicked, this, [this](){ playSound(8); });
    connect(ui->b9, &QPushButton::clicked, this, [this](){ playSound(9); });
    connect(ui->b10, &QPushButton::clicked, this, [this](){ playSound(10); });
    connect(ui->b11, &QPushButton::clicked, this, [this](){ playSound(11); });
    connect(ui->b12, &QPushButton::clicked, this, [this](){ playSound(12); });
    connect(ui->b13, &QPushButton::clicked, this, [this](){ playSound(13); });
    connect(ui->b14, &QPushButton::clicked, this, [this](){ playSound(14); });
    connect(ui->b15, &QPushButton::clicked, this, [this](){ playSound(15); });
}

MainWindow::~MainWindow()
{
    for(int i = 0; i < players.size(); i++) {
        players[i]->stop();
        delete players[i];
        delete audioOutputs[i];
    }
    players.clear();
    audioOutputs.clear();
    
    delete ui;
}

void MainWindow::playSound(int number)
{
    QString soundFile = QString(":/sounds/%1.mp3").arg(number);
    qDebug() << "正在播放文件:" << soundFile;
    QUrl soundUrl = QUrl(QString("qrc%1").arg(soundFile));
    
    QMediaPlayer *availablePlayer = nullptr;
    QAudioOutput *availableOutput = nullptr;
    
    for(int i = 0; i < players.size(); i++) {
        if(players[i]->playbackState() != QMediaPlayer::PlayingState) {
            availablePlayer = players[i];
            availableOutput = audioOutputs[i];
            break;
        }
    }
    
    if(!availablePlayer) {
        availablePlayer = new QMediaPlayer(this);
        availableOutput = new QAudioOutput(this);
        availablePlayer->setAudioOutput(availableOutput);
        availableOutput->setVolume(1.0);
        
        players.append(availablePlayer);
        audioOutputs.append(availableOutput);
        
        connect(availablePlayer, &QMediaPlayer::errorOccurred, 
                this, [this](QMediaPlayer::Error error, const QString &errorString) {
            qDebug() << "播放器错误:" << error << errorString;
        });
    }
    
    qDebug() << "正在播放文件:" << soundFile;
    availablePlayer->setSource(soundUrl);
    availablePlayer->play();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()) return;
    pressedKeys.insert(event->key());
    
    switch(event->key()) {
        case Qt::Key_Q:
            playSound(1);
            ui->b1->setDown(true);
            break;
        case Qt::Key_W:
            playSound(2);
            ui->b2->setDown(true);
            break;
        case Qt::Key_E:
            playSound(3);
            ui->b3->setDown(true);
            break;
        case Qt::Key_R:
            playSound(4);
            ui->b4->setDown(true);
            break;
        case Qt::Key_T:
            playSound(5);
            ui->b5->setDown(true);
            break;
        case Qt::Key_A:
            playSound(6);
            ui->b6->setDown(true);
            break;
        case Qt::Key_S:
            playSound(7);
            ui->b7->setDown(true);
            break;
        case Qt::Key_D:
            playSound(8);
            ui->b8->setDown(true);
            break;
        case Qt::Key_F:
            playSound(9);
            ui->b9->setDown(true);
            break;
        case Qt::Key_G:
            playSound(10);
            ui->b10->setDown(true);
            break;
        case Qt::Key_Z:
            playSound(11);
            ui->b11->setDown(true);
            break;
        case Qt::Key_X:
            playSound(12);
            ui->b12->setDown(true);
            break;
        case Qt::Key_C:
            playSound(13);
            ui->b13->setDown(true);
            break;
        case Qt::Key_V:
            playSound(14);
            ui->b14->setDown(true);
            break;
        case Qt::Key_B:
            playSound(15);
            ui->b15->setDown(true);
            break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    pressedKeys.remove(event->key());
    
    switch(event->key()) {
        case Qt::Key_Q:
            ui->b1->setDown(false);
            break;
        case Qt::Key_W:
            ui->b2->setDown(false);
            break;
        case Qt::Key_E:
            ui->b3->setDown(false);
            break;
        case Qt::Key_R:
            ui->b4->setDown(false);
            break;
        case Qt::Key_T:
            ui->b5->setDown(false);
            break;
        case Qt::Key_A:
            ui->b6->setDown(false);
            break;
        case Qt::Key_S:
            ui->b7->setDown(false);
            break;
        case Qt::Key_D:
            ui->b8->setDown(false);
            break;
        case Qt::Key_F:
            ui->b9->setDown(false);
            break;
        case Qt::Key_G:
            ui->b10->setDown(false);
            break;
        case Qt::Key_Z:
            ui->b11->setDown(false);
            break;
        case Qt::Key_X:
            ui->b12->setDown(false);
            break;
        case Qt::Key_C:
            ui->b13->setDown(false);
            break;
        case Qt::Key_V:
            ui->b14->setDown(false);
            break;
        case Qt::Key_B:
            ui->b15->setDown(false);
            break;
    }
}
