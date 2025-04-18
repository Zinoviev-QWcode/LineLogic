#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QDialog>
#include "logic.h"

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QDialog
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();
    void clear();
    void error();
    QString getLogin();

signals:
    void registrate(QString,QString,QString,QString,QString);

private slots:


    void on_upin_clicked();
    void on_Log_in_clicked();
    void on_lineEdit_login_textChanged(const QString &arg1);
    void on_lineEdit_pass_textChanged(const QString &arg1);

    void on_lineEdit_Nick_textChanged(const QString &arg1);

    void on_lineEdit_check_textChanged(const QString &arg1);

    void on_lineEdit_mail_textChanged(const QString &arg1);

    void on_Reg_in_clicked();

private:
    Ui::AuthRegForm *ui;
    void Reg_mode(bool is_reg);
    bool conds[5] = {0,0,0,0,0};
    bool allConditions(bool cons[]);

};

#endif // AUTHREGFORM_H
