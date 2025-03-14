#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QList>
#include <QString>
#include <QQueue>
#include <QMutex>

class AudioManager : public QObject
{
    Q_OBJECT
public:
    explicit AudioManager(QObject *parent = nullptr);
    ~AudioManager();

public slots:
    void playSound(const QString& soundFile);

private:
    QMediaPlayer* getAvailablePlayer();
    void recyclePlayer(QMediaPlayer* player);
    
    QList<QMediaPlayer*> m_players;
    QList<QAudioOutput*> m_audioOutputs;
    QQueue<QMediaPlayer*> m_availablePlayers;
    QMutex m_mutex;
    
    static constexpr int INITIAL_PLAYER_COUNT = 15;
    static constexpr int MAX_PLAYER_COUNT = 30;  // 最大播放器数量
};

#endif // AUDIOMANAGER_H 