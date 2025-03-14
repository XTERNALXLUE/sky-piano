#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPushButton>
#include "audiomanager.h"
#include "backgroundmanager.h"
#include "pianokey.h"

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

private slots:
    void onKeyStateChanged(int keyNumber, bool pressed);
    void onBackgroundChanged();
    void selectBackground();

private:
    void setupPianoKeys();
    void setupConnections();
    QPushButton* getButtonForKey(int keyNumber);

    Ui::MainWindow *ui;
    AudioManager *m_audioManager;
    BackgroundManager *m_backgroundManager;
    QMap<int, PianoKey*> m_pianoKeys;
};

#endif // MAINWINDOW_H
