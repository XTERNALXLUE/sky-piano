#include "audiomanager.h"
#include <QUrl>
#include <QDebug>

AudioManager::AudioManager(QObject *parent)
    : QObject(parent)
{
    // 初始化播放器池
    for(int i = 0; i < INITIAL_PLAYER_COUNT; i++) {
        QMediaPlayer *player = new QMediaPlayer(this);
        QAudioOutput *audioOutput = new QAudioOutput(this);
        player->setAudioOutput(audioOutput);
        audioOutput->setVolume(1.0);
        
        m_players.append(player);
        m_audioOutputs.append(audioOutput);
        m_availablePlayers.enqueue(player);
        
        // 连接播放结束信号
        connect(player, &QMediaPlayer::playbackStateChanged, this, [this, player](QMediaPlayer::PlaybackState state) {
            if (state == QMediaPlayer::StoppedState) {
                recyclePlayer(player);
            }
        });
    }
}

AudioManager::~AudioManager()
{
    for(auto player : m_players) {
        player->stop();
        delete player;
    }
    for(auto output : m_audioOutputs) {
        delete output;
    }
    m_players.clear();
    m_audioOutputs.clear();
    m_availablePlayers.clear();
}

void AudioManager::playSound(const QString& soundFile)
{
    QMutexLocker locker(&m_mutex);
    
    QUrl soundUrl = QUrl(QString("qrc%1").arg(soundFile));
    QMediaPlayer *player = getAvailablePlayer();
    
    if (player) {
        player->setSource(soundUrl);
        player->play();
    } else {
        qDebug() << "No available player for sound:" << soundFile;
    }
}

QMediaPlayer* AudioManager::getAvailablePlayer()
{
    // 首先尝试从可用播放器队列中获取
    if (!m_availablePlayers.isEmpty()) {
        return m_availablePlayers.dequeue();
    }
    
    // 如果没有可用的播放器，检查是否达到最大数量
    if (m_players.size() >= MAX_PLAYER_COUNT) {
        return nullptr;
    }
    
    // 创建新的播放器
    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(1.0);
    
    m_players.append(player);
    m_audioOutputs.append(audioOutput);
    
    // 连接播放结束信号
    connect(player, &QMediaPlayer::playbackStateChanged, this, [this, player](QMediaPlayer::PlaybackState state) {
        if (state == QMediaPlayer::StoppedState) {
            recyclePlayer(player);
        }
    });
    
    return player;
}

void AudioManager::recyclePlayer(QMediaPlayer* player)
{
    QMutexLocker locker(&m_mutex);
    if (!m_availablePlayers.contains(player)) {
        m_availablePlayers.enqueue(player);
    }
} 