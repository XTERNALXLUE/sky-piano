/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *b8;
    QPushButton *b6;
    QPushButton *b7;
    QPushButton *b1;
    QPushButton *b4;
    QPushButton *b5;
    QPushButton *b11;
    QPushButton *b12;
    QPushButton *b13;
    QPushButton *b9;
    QPushButton *b15;
    QPushButton *b2;
    QPushButton *b10;
    QPushButton *b14;
    QPushButton *b3;
    QMenuBar *menubar;
    QMenu *menusettings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 450);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        b8 = new QPushButton(centralwidget);
        b8->setObjectName("b8");
        b8->setGeometry(QRect(370, 169, 80, 80));
        b6 = new QPushButton(centralwidget);
        b6->setObjectName("b6");
        b6->setGeometry(QRect(72, 169, 80, 80));
        b7 = new QPushButton(centralwidget);
        b7->setObjectName("b7");
        b7->setGeometry(QRect(222, 169, 80, 80));
        b1 = new QPushButton(centralwidget);
        b1->setObjectName("b1");
        b1->setGeometry(QRect(72, 40, 80, 80));
        b1->setFlat(false);
        b4 = new QPushButton(centralwidget);
        b4->setObjectName("b4");
        b4->setGeometry(QRect(511, 40, 80, 80));
        b5 = new QPushButton(centralwidget);
        b5->setObjectName("b5");
        b5->setGeometry(QRect(652, 40, 80, 80));
        b11 = new QPushButton(centralwidget);
        b11->setObjectName("b11");
        b11->setGeometry(QRect(72, 298, 80, 80));
        b12 = new QPushButton(centralwidget);
        b12->setObjectName("b12");
        b12->setGeometry(QRect(222, 298, 80, 80));
        b13 = new QPushButton(centralwidget);
        b13->setObjectName("b13");
        b13->setGeometry(QRect(370, 298, 80, 80));
        b9 = new QPushButton(centralwidget);
        b9->setObjectName("b9");
        b9->setGeometry(QRect(511, 169, 80, 80));
        b15 = new QPushButton(centralwidget);
        b15->setObjectName("b15");
        b15->setGeometry(QRect(652, 298, 80, 80));
        b2 = new QPushButton(centralwidget);
        b2->setObjectName("b2");
        b2->setGeometry(QRect(222, 40, 80, 80));
        b10 = new QPushButton(centralwidget);
        b10->setObjectName("b10");
        b10->setGeometry(QRect(652, 169, 80, 80));
        b14 = new QPushButton(centralwidget);
        b14->setObjectName("b14");
        b14->setGeometry(QRect(511, 298, 80, 80));
        b3 = new QPushButton(centralwidget);
        b3->setObjectName("b3");
        b3->setGeometry(QRect(370, 40, 80, 80));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menusettings = new QMenu(menubar);
        menusettings->setObjectName("menusettings");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menusettings->menuAction());

        retranslateUi(MainWindow);

        b1->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        b8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b11->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b12->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b13->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b9->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b15->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b10->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b14->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        b3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        menusettings->setTitle(QCoreApplication::translate("MainWindow", "settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
