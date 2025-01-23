#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDebug>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QSet>
#include <QPixmap>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::MainWindow *ui;
    QList<QMediaPlayer*> players;
    QList<QAudioOutput*> audioOutputs;
    QSet<int> pressedKeys;
    QPixmap backgroundImage;
    
private slots:
    void playSound(int number);
    void setBackground();
    void loadBackgroundImage();  // 添加加载背景图片的私有函数
};
#endif // MAINWINDOW_H
