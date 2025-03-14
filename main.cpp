#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // 设置应用程序图标
    QIcon appIcon(":/icons/app.png");
    a.setWindowIcon(appIcon);
    
    MainWindow w;
    w.show();
    return a.exec();
}
