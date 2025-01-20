#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDebug>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QSet>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    Ui::Widget *ui;
    QList<QMediaPlayer*> players;  // 使用播放器列表替代单个播放器
    QList<QAudioOutput*> audioOutputs;  // 对应的音频输出列表
    QSet<int> pressedKeys;  // 用于跟踪当前按下的键
    
private slots:
    void playSound(int number);
};
#endif // WIDGET_H
