#include "authregform.h"
#include "ui_authregform.h"
#include "QKeyEvent"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);
    Reg_mode(false);
    ui->Log_in->setEnabled(false);
    ui->Log_in->setStyleSheet("background-color: rgb(90, 90, 90); color: rgb(255, 255, 255);");
    ui->Reg_in->setEnabled(false);
    ui->Reg_in->setStyleSheet("background-color: rgb(90, 90, 90); color: rgb(255, 255, 255);");


}

void AuthRegForm::Reg_mode(bool is_reg) {
    ui->label_check->setVisible(is_reg);
    ui->label_mail->setVisible(is_reg);
    ui->label_Nick->setVisible(is_reg);
    ui->lineEdit_check->setVisible(is_reg);
    ui->lineEdit_mail->setVisible(is_reg);
    ui->lineEdit_Nick->setVisible(is_reg);
    ui->Reg_in->setVisible(is_reg);
    ui->Log_in->setVisible(!is_reg);
    ui->upin->setText(is_reg ? "Sign in" : "Sign up");
    ui->banner->setText(is_reg ? "REGISTRATION" : "AUTHORIZATION");
    ui->hint->setText(is_reg ? "Have an account? Press 'Sign in' " : "Have no account? Press 'Sign up' ");



}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}






void AuthRegForm::on_upin_clicked()
{
    Reg_mode(!ui->label_check->isVisible());
    clear();
}

void AuthRegForm::clear() {
    ui->lineEdit_login->setText("");
    ui->lineEdit_pass->setText("");
    ui->lineEdit_check->setText("");
    ui->lineEdit_Nick->setText("");
    ui->lineEdit_mail->setText("");
}

void AuthRegForm::error()
{
    ui->hint->setText("Error! This user doesn't exist! Try again.");
}

QString AuthRegForm::getLogin()
{
    return ui->lineEdit_login->text();
}

bool AuthRegForm::allConditions(bool cons[5])
{
    for (int i = 0; i<5;i++){
        if (cons[i] == false) {return cons[i];}
    }
    return true;
}


void AuthRegForm::on_Log_in_clicked()
{
    authorize(ui->lineEdit_login->text(),ui->lineEdit_pass->text());
}



void AuthRegForm::on_lineEdit_login_textChanged(const QString &arg1)
{
    conds[0] = !(arg1.length() < 4 || arg1.contains(" "));
    ui->Log_in->setEnabled(conds[0] && conds[2]);
    ui->Log_in->setStyleSheet( !(conds[0] && conds[2]) ? "background-color: rgb(90, 90, 90); color: rgb(255, 255, 255);" : "background-color: rgb(231, 73, 216); color: rgb(255, 255, 255);");
    ui->Reg_in->setStyleSheet( !(allConditions(conds)) ? "background-color: rgb(90, 90, 90); color: rgb(255, 255, 255);" : "background-color: rgb(231, 73, 216); color: rgb(255, 255, 255);");
    ui->Reg_in->setEnabled(allConditions(conds));
}


void AuthRegForm::on_lineEdit_pass_textChanged(const QString &arg2)
{
    conds[2] = !(arg2.length() <4 || arg2.contains(" "));
    ui->Log_in->setEnabled(conds[0] && conds[2]);
    ui->Log_in->setStyleSheet( !(conds[0] && conds[2]) ? "background-color: rgb(90, 90, 90); color: rgb(255, 255, 255);" : "background-color: rgb(231, 73, 216); color: rgb(255, 255, 255);");
    ui->Reg_in->setEnabled(allConditions(conds));
    ui->Reg_in->setStyleSheet( !(allConditions(conds)) ? "background-color: rgb(90, 90, 90); color: rgb(255, 255, 255);" : "background-color: rgb(231, 73, 216); color: rgb(255, 255, 255);");


}


void AuthRegForm::on_lineEdit_Nick_textChanged(const QString &arg1)
{
    conds[1] = !(arg1.length() < 4 || arg1.contains(" ") );
    ui->Reg_in->setEnabled(allConditions(conds));
    ui->Reg_in->setStyleSheet( !(allConditions(conds)) ? "background-color: rgb(90, 90, 90); color: rgb(255, 255, 255);" : "background-color: rgb(231, 73, 216); color: rgb(255, 255, 255);");

}


void AuthRegForm::on_lineEdit_check_textChanged(const QString &arg1)
{
    conds[3] = !(arg1.length() < 4 || arg1.contains(" ") || arg1 != ui->lineEdit_pass->text());
    ui->Reg_in->setEnabled(allConditions(conds));
    ui->Reg_in->setStyleSheet( !(allConditions(conds)) ? "background-color: rgb(90, 90, 90); color: rgb(255, 255, 255);" : "background-color: rgb(231, 73, 216); color: rgb(255, 255, 255);");
}


void AuthRegForm::on_lineEdit_mail_textChanged(const QString &arg1)
{
    conds[4] = !(arg1.length() < 4 || arg1.contains(" "));
    ui->Reg_in->setEnabled(allConditions(conds));
    ui->Reg_in->setStyleSheet( !(allConditions(conds)) ? "background-color: rgb(90, 90, 90); color: rgb(255, 255, 255);" : "background-color: rgb(231, 73, 216); color: rgb(255, 255, 255);");

}


void AuthRegForm::on_Reg_in_clicked()
{
    reg(ui->lineEdit_login->text(),ui->lineEdit_Nick->text(), ui->lineEdit_pass->text(), ui->lineEdit_mail->text());
}

