#include "logic.h"
#include "singletonclient.h"


void authorize(QString log, QString password)
{
    QString message = "LOGIN " + log + " " + password;
    singletonclient::getInst() -> sendToServer(message);
}







void reg(QString log, QString nick, QString password, QString mail)
{
    QString message = "REGISTER " + log + " " + nick + " " + password + " " + mail;
    singletonclient::getInst()->sendToServer(message);
}

void logout()
{
    QString login = singletonclient::getInst() -> Username;
    QString message = "LOGOUT " + login;
    singletonclient::getInst()->sendToServer(message);
}

void createQ(QString name)
{
    QString message = "CREATE " + name + " BY " + singletonclient::getInst()->Username;
    singletonclient::getInst()->sendToServer(message);
}

void GoToQ(QString QID)
{
    while (QID.startsWith('0')) { QID.remove(0,1); }
    QString message = "GO " + QID + " BY " + singletonclient::getInst()->Username;
    singletonclient::getInst()->sendToServer(message);
}

void leaveQ(QString QID)
{
    while (QID.startsWith('0')) { QID.remove(0,1); }
    QString message = "LEAVE " + singletonclient::getInst()->Username + " " + QID;
    singletonclient::getInst()->sendToServer(message);
}
