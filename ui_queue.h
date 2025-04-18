/********************************************************************************
** Form generated from reading UI file 'queue.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEUE_H
#define UI_QUEUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Queue
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *QID_Label;
    QLabel *QID;
    QLabel *Line;
    QLabel *Name;
    QLabel *Place;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_6;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_7;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *label_8;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLabel *label_9;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *label_10;
    QPushButton *pushButton;

    void setupUi(QDialog *Queue)
    {
        if (Queue->objectName().isEmpty())
            Queue->setObjectName("Queue");
        Queue->resize(736, 496);
        Queue->setMinimumSize(QSize(736, 496));
        Queue->setMaximumSize(QSize(736, 496));
        Queue->setStyleSheet(QString::fromUtf8("background-color: rgb(67, 67, 67);"));
        horizontalLayoutWidget = new QWidget(Queue);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(470, 420, 261, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        QID_Label = new QLabel(horizontalLayoutWidget);
        QID_Label->setObjectName("QID_Label");
        QID_Label->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(QID_Label);

        QID = new QLabel(horizontalLayoutWidget);
        QID->setObjectName("QID");
        QID->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(QID);

        Line = new QLabel(Queue);
        Line->setObjectName("Line");
        Line->setGeometry(QRect(480, 200, 231, 31));
        Line->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        Name = new QLabel(Queue);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(0, 10, 321, 93));
        Name->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        Name->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Place = new QLabel(Queue);
        Place->setObjectName("Place");
        Place->setGeometry(QRect(550, 240, 101, 41));
        Place->setStyleSheet(QString::fromUtf8("font: 600 20pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        horizontalLayoutWidget_2 = new QWidget(Queue);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(20, 130, 401, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(80);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label);

        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_6);

        horizontalLayoutWidget_3 = new QWidget(Queue);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(20, 190, 401, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(80);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_3);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_2);

        label_7 = new QLabel(horizontalLayoutWidget_3);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_7);

        horizontalLayoutWidget_4 = new QWidget(Queue);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(20, 250, 401, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(80);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_4);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(label_3);

        label_8 = new QLabel(horizontalLayoutWidget_4);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(label_8);

        horizontalLayoutWidget_5 = new QWidget(Queue);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(20, 310, 401, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setSpacing(80);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_5);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(label_4);

        label_9 = new QLabel(horizontalLayoutWidget_5);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(label_9);

        horizontalLayoutWidget_6 = new QWidget(Queue);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(20, 370, 401, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setSpacing(80);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_6);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(label_5);

        label_10 = new QLabel(horizontalLayoutWidget_6);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(label_10);

        pushButton = new QPushButton(Queue);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 440, 171, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 58, 216);\n"
"font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;                      \n"
"border: 2px solid  rgb(185,58,216)"));

        retranslateUi(Queue);

        QMetaObject::connectSlotsByName(Queue);
    } // setupUi

    void retranslateUi(QDialog *Queue)
    {
        Queue->setWindowTitle(QCoreApplication::translate("Queue", "Queue", nullptr));
        QID_Label->setText(QCoreApplication::translate("Queue", "<html><head/><body><p align=\"center\">QUEUE'S ID:</p></body></html>", nullptr));
        QID->setText(QCoreApplication::translate("Queue", "00000000", nullptr));
        Line->setText(QCoreApplication::translate("Queue", "<html><head/><body><p align=\"center\">YOUR PLACE IN QUEUE:<br/></p></body></html>", nullptr));
        Name->setText(QCoreApplication::translate("Queue", "<html><head/><body><p align=\"center\">QUEUE'S NAME</p></body></html>", nullptr));
        Place->setText(QCoreApplication::translate("Queue", "<html><head/><body><p align=\"center\">100</p></body></html>", nullptr));
        label->setText(QString());
        label_6->setText(QString());
        label_2->setText(QString());
        label_7->setText(QString());
        label_3->setText(QString());
        label_8->setText(QString());
        label_4->setText(QString());
        label_9->setText(QString());
        label_5->setText(QString());
        label_10->setText(QString());
        pushButton->setText(QCoreApplication::translate("Queue", "LEAVE THE QUEUE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Queue: public Ui_Queue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEUE_H
