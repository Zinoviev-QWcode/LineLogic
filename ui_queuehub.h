/********************************************************************************
** Form generated from reading UI file 'queuehub.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEUEHUB_H
#define UI_QUEUEHUB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueueHub
{
public:
    QPushButton *LogOut;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Greetings;
    QLabel *label;
    QLabel *logo;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_QID;
    QPushButton *GoToQueue;
    QHBoxLayout *horizontalLayout;
    QPushButton *CreateQueue;

    void setupUi(QDialog *QueueHub)
    {
        if (QueueHub->objectName().isEmpty())
            QueueHub->setObjectName("QueueHub");
        QueueHub->resize(763, 466);
        QueueHub->setMinimumSize(QSize(763, 466));
        QueueHub->setMaximumSize(QSize(763, 466));
        QueueHub->setStyleSheet(QString::fromUtf8("background-color: rgb(67, 67, 67);"));
        LogOut = new QPushButton(QueueHub);
        LogOut->setObjectName("LogOut");
        LogOut->setGeometry(QRect(10, 20, 111, 41));
        LogOut->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 58, 173);\n"
"font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;                      \n"
"border: 2px solid  rgb(185,58,173)"));
        LogOut->setAutoDefault(false);
        verticalLayoutWidget = new QWidget(QueueHub);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(200, 0, 436, 448));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Greetings = new QLabel(verticalLayoutWidget);
        Greetings->setObjectName("Greetings");
        Greetings->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(Greetings);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label);

        logo = new QLabel(verticalLayoutWidget);
        logo->setObjectName("logo");
        logo->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/Pictuh.png")));
        logo->setScaledContents(true);

        verticalLayout->addWidget(logo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_QID = new QLineEdit(verticalLayoutWidget);
        lineEdit_QID->setObjectName("lineEdit_QID");
        lineEdit_QID->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(lineEdit_QID);

        GoToQueue = new QPushButton(verticalLayoutWidget);
        GoToQueue->setObjectName("GoToQueue");
        GoToQueue->setMinimumSize(QSize(70, 40));
        GoToQueue->setMaximumSize(QSize(70, 40));
        GoToQueue->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 58, 216);\n"
"font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;\n"
" border: 2px solid  rgb(185,58,216)"));
        GoToQueue->setAutoDefault(true);

        horizontalLayout_2->addWidget(GoToQueue);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        CreateQueue = new QPushButton(verticalLayoutWidget);
        CreateQueue->setObjectName("CreateQueue");
        CreateQueue->setMinimumSize(QSize(200, 40));
        CreateQueue->setMaximumSize(QSize(200, 40));
        CreateQueue->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 73, 216);\n"
"font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;                      \n"
"border: 2px solid  rgb(231,73,216)"));
        CreateQueue->setAutoDefault(false);

        horizontalLayout->addWidget(CreateQueue);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QueueHub);

        QMetaObject::connectSlotsByName(QueueHub);
    } // setupUi

    void retranslateUi(QDialog *QueueHub)
    {
        QueueHub->setWindowTitle(QCoreApplication::translate("QueueHub", "Hub", nullptr));
        LogOut->setText(QCoreApplication::translate("QueueHub", "Log out", nullptr));
        Greetings->setText(QCoreApplication::translate("QueueHub", "<html><head/><body><p align=\"center\">GREETINGS!</p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("QueueHub", "<html><head/><body><p align=\"center\">Enter the Queue ID(8 characters) and Click \342\200\230Go!\342\200\231</p><p align=\"center\">to join the queue, or create your own</p></body></html>", nullptr));
        logo->setText(QString());
        GoToQueue->setText(QCoreApplication::translate("QueueHub", "Go!", nullptr));
        CreateQueue->setText(QCoreApplication::translate("QueueHub", "Create a new queue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueueHub: public Ui_QueueHub {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEUEHUB_H
