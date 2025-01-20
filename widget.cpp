#include "widget.h"
#include "ui_widget.h"
#include <QMediaPlayer>
#include <QtMultimedia/QMediaPlayer>
#include <QDebug>
#include <QFileInfo>
#include <QAudioOutput>
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(800, 450);
    
    // 预先创建多个播放器和音频输出（比如5个，可以同时播放5个音频）
    for(int i = 0; i < 15; i++) {
        QMediaPlayer *player = new QMediaPlayer(this);
        QAudioOutput *audioOutput = new QAudioOutput(this);
        player->setAudioOutput(audioOutput);
        audioOutput->setVolume(1.0);
        
        players.append(player);
        audioOutputs.append(audioOutput);
    }

    // 连接按钮信号到槽
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

Widget::~Widget()
{
    // 清理所有播放器和音频输出
    for(int i = 0; i < players.size(); i++) {
        players[i]->stop();
        delete players[i];
        delete audioOutputs[i];
    }
    players.clear();
    audioOutputs.clear();
    
    delete ui;
}

void Widget::playSound(int number)
{
    // 使用资源路径而不是文件系统路径
    QString soundFile = QString(":/sounds/%1.mp3").arg(number);
    
    // 不需要检查文件是否存在，因为资源文件在编译时就已经确保存在
    qDebug() << "正在播放文件:" << soundFile;
    
    // 使用 QUrl 的 qrc 方案
    QUrl soundUrl = QUrl(QString("qrc%1").arg(soundFile));
    
    // 查找空闲的播放器
    QMediaPlayer *availablePlayer = nullptr;
    QAudioOutput *availableOutput = nullptr;
    
    // 遍历查找未在播放状态的播放器
    for(int i = 0; i < players.size(); i++) {
        if(players[i]->playbackState() != QMediaPlayer::PlayingState) {
            availablePlayer = players[i];
            availableOutput = audioOutputs[i];
            break;
        }
    }
    
    // 如果没有找到空闲播放器，创建新的播放器
    if(!availablePlayer) {
        availablePlayer = new QMediaPlayer(this);
        availableOutput = new QAudioOutput(this);
        availablePlayer->setAudioOutput(availableOutput);
        availableOutput->setVolume(1.0);
        
        players.append(availablePlayer);
        audioOutputs.append(availableOutput);
        
        // 添加错误处理
        connect(availablePlayer, &QMediaPlayer::errorOccurred, 
                this, [this](QMediaPlayer::Error error, const QString &errorString) {
            qDebug() << "播放器错误:" << error << errorString;
        });
    }
    
    qDebug() << "正在播放文件:" << soundFile;
    availablePlayer->setSource(soundUrl);
    availablePlayer->play();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat()) return;  // 防止按住键盘重复触发
    
    // 记录这个键被按下
    pressedKeys.insert(event->key());
    
    // 处理新按下的键
    switch(event->key()) {
        case Qt::Key_Q:
            playSound(1);
            ui->b1->setDown(true);  // 显示按钮被按下的状态
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

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    // 从已按下的键集合中移除
    pressedKeys.remove(event->key());
    
    // 处理释放的键
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
