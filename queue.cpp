#include "queue.h"
#include "ui_queue.h"
#include "logic.h"
Queue::Queue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Queue)
{
    ui->setupUi(this);
    labels = {ui->label, ui->label_2, ui->label_3,ui->label_4,ui->label_5,ui->label_6,ui->label_7,ui->label_8,ui->label_9,ui->label_10};
}

Queue::~Queue()
{
    delete ui;
}

void Queue::QMaker(QString name)
{
    ui->Name->setText(name);
}

void Queue::Qfiller(QString nick, int position)
{

    labels[position]->setText(nick);
}

void Queue::setQID(QString QID)
{
    ui->QID->setText(QString::number(QID.toInt()).rightJustified(8, '0'));
}

void Queue::setPosition(QString pos)
{
    ui->Place->setText(pos);
}

QString Queue::getPosition()
{
    return ui->Place->text();
}

void Queue::update(QString position)
{
    int pos = position.toInt();
    pos--;
    for(int i = pos; i<9;i++) {
        labels[i]->setText(labels[i+1]->text());
    }
}

void Queue::clear()
{
    ui->Name->setText("");
    ui->QID->setText("");
    ui->Place->setText("");
    for (auto& n : labels) {
        n->setText("");
    }

}

void Queue::on_pushButton_clicked()
{
    emit GoBack();
    leaveQ(ui->QID->text());

}

