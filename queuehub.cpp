#include "queuehub.h"
#include "ui_queuehub.h"

QueueHub::QueueHub(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QueueHub)
{
    ui->setupUi(this);
    ui->GoToQueue->setEnabled(false);
    ui->GoToQueue->setStyleSheet("background-color: rgb(90, 90, 90); color: rgb(255, 255, 255); border-radius: 20px; border: 2px solid  rgb(90,90,90)");
}

QueueHub::~QueueHub()
{
    delete ui;
}

void QueueHub::clear()
{
    ui->lineEdit_QID->setText("");
}

void QueueHub::on_LogOut_clicked()
{
    logout();
}


void QueueHub::on_GoToQueue_clicked()
{
    GoToQ(ui->lineEdit_QID->text());
}


void QueueHub::on_CreateQueue_clicked()
{
    emit goCreate();
}


void QueueHub::on_lineEdit_QID_textChanged(const QString &arg1)
{
    bool Approved = (arg1.length() == 8);
    ui->GoToQueue->setEnabled(Approved);
    ui->GoToQueue->setStyleSheet( !Approved ? "background-color: rgb(90, 90, 90); color: rgb(255, 255, 255); border-radius: 20px; border: 2px solid  rgb(90,90,90)" : "background-color: rgb(185, 58, 173); color: rgb(255, 255, 255); border-radius: 20px; border: 2px solid  rgb(185,58,173)");
}

