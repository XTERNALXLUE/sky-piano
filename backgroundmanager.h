#ifndef BACKGROUNDMANAGER_H
#define BACKGROUNDMANAGER_H

#include <QObject>
#include <QPixmap>
#include <QString>

class BackgroundManager : public QObject
{
    Q_OBJECT
public:
    explicit BackgroundManager(QObject *parent = nullptr);
    
    void loadBackgroundImage();
    bool setBackgroundFromFile(const QString& filePath);
    const QPixmap& currentBackground() const { return m_backgroundImage; }

signals:
    void backgroundChanged();

private:
    static const QString BACKGROUND_DIR;
    QPixmap m_backgroundImage;
    
    void ensureDirectoryExists();
    void clearOldBackgrounds();
};

#endif // BACKGROUNDMANAGER_H 