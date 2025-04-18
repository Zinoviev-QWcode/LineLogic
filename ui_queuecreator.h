/********************************************************************************
** Form generated from reading UI file 'queuecreator.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEUECREATOR_H
#define UI_QUEUECREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueueCreator
{
public:
    QLabel *Logo;
    QLabel *hint;
    QLineEdit *QueueName;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Cancel;
    QPushButton *Create;

    void setupUi(QDialog *QueueCreator)
    {
        if (QueueCreator->objectName().isEmpty())
            QueueCreator->setObjectName("QueueCreator");
        QueueCreator->resize(400, 382);
        QueueCreator->setMinimumSize(QSize(400, 382));
        QueueCreator->setMaximumSize(QSize(400, 382));
        QueueCreator->setStyleSheet(QString::fromUtf8("background-color: rgb(67, 67, 67);"));
        Logo = new QLabel(QueueCreator);
        Logo->setObjectName("Logo");
        Logo->setGeometry(QRect(120, 20, 161, 131));
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/Pictuh.png")));
        Logo->setScaledContents(true);
        hint = new QLabel(QueueCreator);
        hint->setObjectName("hint");
        hint->setGeometry(QRect(10, 170, 381, 41));
        hint->setStyleSheet(QString::fromUtf8("font: 600 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        QueueName = new QLineEdit(QueueCreator);
        QueueName->setObjectName("QueueName");
        QueueName->setGeometry(QRect(70, 230, 281, 31));
        QueueName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayoutWidget = new QWidget(QueueCreator);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(60, 270, 309, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Cancel = new QPushButton(horizontalLayoutWidget);
        Cancel->setObjectName("Cancel");
        Cancel->setMinimumSize(QSize(150, 40));
        Cancel->setMaximumSize(QSize(150, 40));
        Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 58, 216);\n"
"font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;                      \n"
"border: 2px solid  rgb(185,58,216)"));
        Cancel->setAutoDefault(false);

        horizontalLayout->addWidget(Cancel);

        Create = new QPushButton(horizontalLayoutWidget);
        Create->setObjectName("Create");
        Create->setMinimumSize(QSize(150, 40));
        Create->setMaximumSize(QSize(150, 40));
        Create->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 73, 216);\n"
"font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;                      \n"
"border: 2px solid  rgb(231,73,216)"));

        horizontalLayout->addWidget(Create);


        retranslateUi(QueueCreator);

        QMetaObject::connectSlotsByName(QueueCreator);
    } // setupUi

    void retranslateUi(QDialog *QueueCreator)
    {
        QueueCreator->setWindowTitle(QCoreApplication::translate("QueueCreator", "Creator", nullptr));
        Logo->setText(QString());
        hint->setText(QCoreApplication::translate("QueueCreator", "<html><head/><body><p align=\"center\">Enter a name for your queue (&gt;3 characters)</p></body></html>", nullptr));
        Cancel->setText(QCoreApplication::translate("QueueCreator", "Cancel", nullptr));
        Create->setText(QCoreApplication::translate("QueueCreator", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueueCreator: public Ui_QueueCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEUECREATOR_H
