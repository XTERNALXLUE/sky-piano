#include "backgroundmanager.h"
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>
#include <QFile>

const QString BackgroundManager::BACKGROUND_DIR = "resource/img";

BackgroundManager::BackgroundManager(QObject *parent)
    : QObject(parent)
{
    ensureDirectoryExists();
    loadBackgroundImage();
}

void BackgroundManager::ensureDirectoryExists()
{
    QDir().mkpath(BACKGROUND_DIR);
}

void BackgroundManager::loadBackgroundImage()
{
    QDir imgDir(BACKGROUND_DIR);
    QStringList filters;
    filters << "background.*";
    QStringList files = imgDir.entryList(filters, QDir::Files);
    
    if (!files.isEmpty()) {
        QString backgroundPath = BACKGROUND_DIR + "/" + files.first();
        if (m_backgroundImage.load(backgroundPath)) {
            emit backgroundChanged();
        }
    }
}

void BackgroundManager::clearOldBackgrounds()
{
    QDir imgDir(BACKGROUND_DIR);
    QStringList filters;
    filters << "background.*";
    QStringList files = imgDir.entryList(filters, QDir::Files);
    
    for(const QString& file : files) {
        imgDir.remove(file);
    }
}

bool BackgroundManager::setBackgroundFromFile(const QString& filePath)
{
    if (filePath.isEmpty()) {
        return false;
    }

    QFileInfo fileInfo(filePath);
    QString extension = fileInfo.suffix();
    QString newPath = QString("%1/background.%2").arg(BACKGROUND_DIR, extension);

    clearOldBackgrounds();
    
    if (QFile::copy(filePath, newPath)) {
        if (m_backgroundImage.load(newPath)) {
            emit backgroundChanged();
            return true;
        }
    }
    
    return false;
} 