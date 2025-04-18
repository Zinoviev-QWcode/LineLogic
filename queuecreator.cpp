#include "queuecreator.h"
#include "ui_queuecreator.h"
#include "logic.h"

QueueCreator::QueueCreator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QueueCreator)
{
    ui->setupUi(this);
    ui->Create->setEnabled(false);
    ui->Create->setStyleSheet("background-color: rgb(90, 90, 90); color: rgb(255, 255, 255); border-radius: 20px; border: 2px solid  rgb(90,90,90)");
}

QueueCreator::~QueueCreator()
{
    delete ui;
}

void QueueCreator::clear()
{
    ui->QueueName->setText("");
}

void QueueCreator::on_Cancel_clicked()
{
    emit GoBack();
}


void QueueCreator::on_Create_clicked()
{

    createQ(ui->QueueName->text());
}


void QueueCreator::on_QueueName_textChanged(const QString &arg1)
{
    bool notApproved = (arg1.length() <4 );
    ui->Create->setEnabled(!notApproved);
    ui->Create->setStyleSheet( notApproved ? "background-color: rgb(90, 90, 90); color: rgb(255, 255, 255); border-radius: 20px; border: 2px solid  rgb(90,90,90)" : "background-color: rgb(231, 73, 216); color: rgb(255, 255, 255); border-radius: 20px;border: 2px solid  rgb(231,73,216)");
}

