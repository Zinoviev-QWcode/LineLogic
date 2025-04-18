/********************************************************************************
** Form generated from reading UI file 'authregform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHREGFORM_H
#define UI_AUTHREGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthRegForm
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Log_in;
    QPushButton *Reg_in;
    QPushButton *upin;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_login;
    QLabel *label_Nick;
    QLineEdit *lineEdit_Nick;
    QLabel *label_pass;
    QLineEdit *lineEdit_pass;
    QLabel *label_check;
    QLineEdit *lineEdit_check;
    QLabel *label_mail;
    QLineEdit *lineEdit_mail;
    QLineEdit *lineEdit_login;
    QLabel *banner;
    QLabel *hint;

    void setupUi(QDialog *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName("AuthRegForm");
        AuthRegForm->resize(427, 323);
        AuthRegForm->setMinimumSize(QSize(427, 323));
        AuthRegForm->setMaximumSize(QSize(427, 323));
        AuthRegForm->setAutoFillBackground(false);
        AuthRegForm->setStyleSheet(QString::fromUtf8("background-color: rgb(67, 67, 67);\n"
"font: 600 10pt \"Segoe UI\";"));
        horizontalLayoutWidget = new QWidget(AuthRegForm);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(60, 220, 311, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Log_in = new QPushButton(horizontalLayoutWidget);
        Log_in->setObjectName("Log_in");
        Log_in->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 73, 216);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 20px;"));
        Log_in->setAutoDefault(false);

        horizontalLayout->addWidget(Log_in);

        Reg_in = new QPushButton(horizontalLayoutWidget);
        Reg_in->setObjectName("Reg_in");
        Reg_in->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 73, 216);\n"
"color: rgb(255, 255, 255);"));
        Reg_in->setAutoDefault(false);

        horizontalLayout->addWidget(Reg_in);

        upin = new QPushButton(horizontalLayoutWidget);
        upin->setObjectName("upin");
        upin->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 58, 173);\n"
"color: rgb(255, 255, 255);"));
        upin->setAutoDefault(false);

        horizontalLayout->addWidget(upin);

        formLayoutWidget = new QWidget(AuthRegForm);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 50, 341, 181));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_login = new QLabel(formLayoutWidget);
        label_login->setObjectName("label_login");
        label_login->setStyleSheet(QString::fromUtf8("font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_login);

        label_Nick = new QLabel(formLayoutWidget);
        label_Nick->setObjectName("label_Nick");
        label_Nick->setStyleSheet(QString::fromUtf8("font: 600 10pt \"Segoe UI\";\n"
"\n"
"color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_Nick);

        lineEdit_Nick = new QLineEdit(formLayoutWidget);
        lineEdit_Nick->setObjectName("lineEdit_Nick");
        lineEdit_Nick->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_Nick);

        label_pass = new QLabel(formLayoutWidget);
        label_pass->setObjectName("label_pass");
        label_pass->setStyleSheet(QString::fromUtf8("font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_pass);

        lineEdit_pass = new QLineEdit(formLayoutWidget);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_pass);

        label_check = new QLabel(formLayoutWidget);
        label_check->setObjectName("label_check");
        label_check->setStyleSheet(QString::fromUtf8("font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_check);

        lineEdit_check = new QLineEdit(formLayoutWidget);
        lineEdit_check->setObjectName("lineEdit_check");
        lineEdit_check->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_check);

        label_mail = new QLabel(formLayoutWidget);
        label_mail->setObjectName("label_mail");
        label_mail->setStyleSheet(QString::fromUtf8("font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_mail);

        lineEdit_mail = new QLineEdit(formLayoutWidget);
        lineEdit_mail->setObjectName("lineEdit_mail");
        lineEdit_mail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_mail);

        lineEdit_login = new QLineEdit(formLayoutWidget);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_login);

        banner = new QLabel(AuthRegForm);
        banner->setObjectName("banner");
        banner->setGeometry(QRect(170, 10, 111, 20));
        banner->setStyleSheet(QString::fromUtf8("font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));
        hint = new QLabel(AuthRegForm);
        hint->setObjectName("hint");
        hint->setGeometry(QRect(120, 290, 201, 20));
        hint->setStyleSheet(QString::fromUtf8("font: 600 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QDialog *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "LineLogic", nullptr));
        Log_in->setText(QCoreApplication::translate("AuthRegForm", "Log in", nullptr));
        Reg_in->setText(QCoreApplication::translate("AuthRegForm", "Reg in", nullptr));
        upin->setText(QCoreApplication::translate("AuthRegForm", "Sign up", nullptr));
        label_login->setText(QCoreApplication::translate("AuthRegForm", "Login", nullptr));
        label_Nick->setText(QCoreApplication::translate("AuthRegForm", "Nickname", nullptr));
        label_pass->setText(QCoreApplication::translate("AuthRegForm", "Password", nullptr));
        label_check->setText(QCoreApplication::translate("AuthRegForm", "Password Check", nullptr));
        label_mail->setText(QCoreApplication::translate("AuthRegForm", "E-mail", nullptr));
        banner->setText(QCoreApplication::translate("AuthRegForm", "Authorization", nullptr));
        hint->setText(QCoreApplication::translate("AuthRegForm", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
