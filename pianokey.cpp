#include "pianokey.h"

PianoKey::PianoKey(int keyNumber, Qt::Key keyboardKey, const QString& soundFile, QObject *parent)
    : QObject(parent)
    , m_keyNumber(keyNumber)
    , m_keyboardKey(keyboardKey)
    , m_soundFile(soundFile)
    , m_isPressed(false)
{
}

void PianoKey::setPressed(bool pressed)
{
    if (m_isPressed != pressed) {
        m_isPressed = pressed;
        emit keyStateChanged(m_keyNumber, pressed);
        if (pressed) {
            emit playRequested(m_soundFile);
        }
    }
} 