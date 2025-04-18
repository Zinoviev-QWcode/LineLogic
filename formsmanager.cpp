#include "formsmanager.h"
#include "authregform.h"
#include "queuehub.h"
#include "queuecreator.h"
#include "queue.h"
#include "logic.h"
#include "singletonclient.h"


#include <QMessageBox>
formsManager::formsManager(QWidget *parent)
    : QMainWindow(parent)
{
    singletonclient::getInst(); //создание экземляра клиента
    this->curr_auth = new AuthRegForm(); // инициализация окон
    this->curr_auth->show();
    this->hub = new QueueHub();
    this->creator = new QueueCreator(); 
    this->q = new Queue();


    //соединение сигналов со слотами//
    connect(singletonclient::getInst(),&singletonclient::authorizationResult, this, &formsManager::fromLoginToHub);
    connect(singletonclient::getInst(),&singletonclient::registrationResult, this, &formsManager::fromRegToHub);
    connect(singletonclient::getInst(),&singletonclient::logout, this, &formsManager::fromHubToLogin);
    connect(singletonclient::getInst(),&singletonclient::added, this, &formsManager::fromHubToQ);
    connect(q,&Queue::GoBack,this,&formsManager::fromQToHub);
    connect(hub,&QueueHub::goCreate,this,&formsManager::fromHubToCreator);
    connect(creator,&QueueCreator::GoBack,this,&formsManager::fromCreatorToHub);
    connect(singletonclient::getInst(),&singletonclient::created, this, &formsManager::fromCreatorToQ);
    connect(singletonclient::getInst(),&singletonclient::newInQ, this, &formsManager::QUpdate);
    connect(singletonclient::getInst(),&singletonclient::left, this, &formsManager::Qleft);


}

formsManager::~formsManager() {}

void formsManager::fromLoginToHub(bool result)
{   
    if (result) {
        singletonclient::getInst() -> Username = this->curr_auth->getLogin();
        this->curr_auth->clear();
        this->curr_auth->hide();
        this->hub->show();
    }
    else{
        this->curr_auth->clear();
        QMessageBox err;
        err.setStyleSheet("background-color: rgb(67, 67, 67); color: rgb(255,255,255); font: 400 12pt 'Segoe UI';");
        err.setWindowTitle("Error");
        err.setText("This user doesn't exist");
        err.setIcon(QMessageBox::Critical);
        err.exec();
    }
}

void formsManager::fromRegToHub(bool result)
{
    if (result) {
        this->curr_auth->clear();
        this->curr_auth->hide();
        this->hub->show();
    }
    else {
        this->curr_auth->clear();
        QMessageBox err;
        err.setStyleSheet("background-color: rgb(67, 67, 67); color: rgb(255,255,255); font: 400 12pt 'Segoe UI';");
        err.setWindowTitle("Error");
        err.setText("The user can't be registered");
        err.setIcon(QMessageBox::Critical);
        err.exec();
    }
}

void formsManager::fromHubToLogin()
{
    this->hub->hide();
    this->curr_auth->show();
}

void formsManager::fromHubToQ(QString QID, QString Qname, QString nick, QString position, QStringList members)
{
    this->hub->clear();
    if (QID == "Error"){
        QMessageBox err;
        err.setStyleSheet("background-color: rgb(67, 67, 67); color: rgb(255,255,255); font: 400 12pt 'Segoe UI';");
        err.setWindowTitle("Error");
        err.setText("This queue doesn't exist");
        err.setIcon(QMessageBox::Critical);
        err.exec();
    }
    else {
        this->hub->close();
        this->q->show();
        this->q->QMaker(Qname);
        this->q->setQID(QID);
        this->q->setPosition(position);
        this->q->Qfiller(nick,position.toInt()-1);
        for (int i = 0; i<members.length();i++){
            this->q->Qfiller(members[i],i);
        }
    }
}


void formsManager::fromQToHub()
{
    this->q->clear();
    this->q->close();
    this->hub->show();
}

void formsManager::fromHubToCreator()
{
    this->hub->clear();
    this->hub->close();
    this->creator->show();
}

void formsManager::fromCreatorToHub()
{
    this->creator->close();
    this->hub->show();
}

void formsManager::fromCreatorToQ(QString name, QString nick, QString QID)
{
    this->q->QMaker(name);
    this->q->Qfiller(nick,0);
    this->q->setPosition("1");
    this->q->setQID(QID);
    this->creator->clear();
    this->creator->close();
    this->q->show();
}

void formsManager::QUpdate(QString nick, QString position)
{
    this->q->Qfiller(nick,position.toInt()-1);
}

void formsManager::Qleft(QString position)
{
    int pos = position.toInt();
    if(pos<this->q->getPosition().toInt()) {
        this->q->setPosition(QString::number(this->q->getPosition().toInt() -1));
    }
    this->q->update(position);
}


