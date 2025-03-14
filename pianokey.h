#ifndef PIANOKEY_H
#define PIANOKEY_H

#include <QObject>
#include <QString>
#include <Qt>

class PianoKey : public QObject
{
    Q_OBJECT
public:
    explicit PianoKey(int keyNumber, Qt::Key keyboardKey, const QString& soundFile, QObject *parent = nullptr);

    int keyNumber() const { return m_keyNumber; }
    Qt::Key keyboardKey() const { return m_keyboardKey; }
    QString soundFile() const { return m_soundFile; }
    bool isPressed() const { return m_isPressed; }
    void setPressed(bool pressed);

signals:
    void keyStateChanged(int keyNumber, bool pressed);
    void playRequested(const QString& soundFile);

private:
    int m_keyNumber;
    Qt::Key m_keyboardKey;
    QString m_soundFile;
    bool m_isPressed;
};

#endif // PIANOKEY_H 