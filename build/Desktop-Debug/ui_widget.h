/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;
    QPushButton *b10;
    QPushButton *b6;
    QPushButton *b7;
    QPushButton *b8;
    QPushButton *b9;
    QPushButton *b11;
    QPushButton *b12;
    QPushButton *b13;
    QPushButton *b14;
    QPushButton *b15;
    QPushButton *b5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 450);
        Widget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	height: 50px;\n"
"}"));
        b1 = new QPushButton(Widget);
        b1->setObjectName("b1");
        b1->setGeometry(QRect(60, 50, 80, 80));
        b1->setFlat(false);
        b2 = new QPushButton(Widget);
        b2->setObjectName("b2");
        b2->setGeometry(QRect(210, 50, 80, 80));
        b3 = new QPushButton(Widget);
        b3->setObjectName("b3");
        b3->setGeometry(QRect(358, 50, 80, 80));
        b4 = new QPushButton(Widget);
        b4->setObjectName("b4");
        b4->setGeometry(QRect(499, 50, 80, 80));
        b10 = new QPushButton(Widget);
        b10->setObjectName("b10");
        b10->setGeometry(QRect(640, 179, 80, 80));
        b6 = new QPushButton(Widget);
        b6->setObjectName("b6");
        b6->setGeometry(QRect(60, 179, 80, 80));
        b7 = new QPushButton(Widget);
        b7->setObjectName("b7");
        b7->setGeometry(QRect(210, 179, 80, 80));
        b8 = new QPushButton(Widget);
        b8->setObjectName("b8");
        b8->setGeometry(QRect(358, 179, 80, 80));
        b9 = new QPushButton(Widget);
        b9->setObjectName("b9");
        b9->setGeometry(QRect(499, 179, 80, 80));
        b11 = new QPushButton(Widget);
        b11->setObjectName("b11");
        b11->setGeometry(QRect(60, 308, 80, 80));
        b12 = new QPushButton(Widget);
        b12->setObjectName("b12");
        b12->setGeometry(QRect(210, 308, 80, 80));
        b13 = new QPushButton(Widget);
        b13->setObjectName("b13");
        b13->setGeometry(QRect(358, 308, 80, 80));
        b14 = new QPushButton(Widget);
        b14->setObjectName("b14");
        b14->setGeometry(QRect(499, 308, 80, 80));
        b15 = new QPushButton(Widget);
        b15->setObjectName("b15");
        b15->setGeometry(QRect(640, 308, 80, 80));
        b5 = new QPushButton(Widget);
        b5->setObjectName("b5");
        b5->setGeometry(QRect(640, 50, 80, 80));

        retranslateUi(Widget);

        b1->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        b1->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b3->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b4->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b10->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b6->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b7->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b8->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b9->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b11->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b12->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b13->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b14->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b15->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        b5->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
