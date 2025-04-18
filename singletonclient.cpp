#include "singletonclient.h"

singletonclient::singletonclient(QObject *parent)
    : QObject{parent}
{
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket->connectToHost("127.0.0.1", 33333);
    connect(mTcpSocket,&QTcpSocket::readyRead, this, &singletonclient::slotReadyRead);
    connect(mTcpSocket,&QTcpSocket::disconnected, mTcpSocket,&QTcpSocket::deleteLater);

}

singletonclient::~singletonclient(){
    this->mTcpSocket->close();
}

singletonclient* singletonclient::getInst(){
    if (!p_instance) {
        p_instance = new singletonclient();
        destroyer.init(p_instance);
    }
    return p_instance;
}

void singletonclient::sendToServer(QString msg)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << msg;
    mTcpSocket->write(data);
}

void singletonclient::messageManager(QString msg)
{
    if(msg.startsWith("LOGIN")) {
        QStringList parsedMessage = msg.split(" ");
        bool result = (parsedMessage[1] == "1" ? true : false);
        emit authorizationResult(result);
    }
    if(msg.startsWith("REGISTER")) {
        QStringList parsedMessage = msg.split(" ");
        bool result = (parsedMessage[1] == "1" ? true : false);
        emit registrationResult(result);
    }
    if(msg.startsWith("LOGOUT")) {
        Username = NULL;
        emit logout();
    }
    if (msg.startsWith("CREATE")) {
        QStringList parsedMessage = msg.split(" ");
        emit created(parsedMessage[1], parsedMessage[2], parsedMessage[3]);
    }
    if (msg.startsWith("ADDED")){
        QStringList parsedMessage = msg.split(" ");
        QStringList members = parsedMessage.sliced(6);
        emit added(parsedMessage[1],parsedMessage[2], parsedMessage[3], parsedMessage[4],members);
    }
    if (msg.startsWith("NEW")) {
       QStringList parsedMessage = msg.split(" ");
       emit newInQ(parsedMessage[1],parsedMessage[2]);
    }
    if (msg.startsWith("LEAVE")) {
       QStringList parsedMessage = msg.split(" ");
        emit left(parsedMessage[1]);
    }

}

void singletonclient::slotReadyRead()
{
    QDataStream in(mTcpSocket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok) {
        qDebug() << "read...";
        QString msg;
        in >> msg;
        qDebug() << msg;
        messageManager(msg);
    }
    else{
        qDebug() << "DATASTREAM ERROR";
    }
}

singletonclient* singletonclient::p_instance;
singletonDestroyer singletonclient::destroyer;


