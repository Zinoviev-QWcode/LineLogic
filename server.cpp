#include "server.h"
#include "databaseinterface.h"
Server::Server() {
    if(this->listen(QHostAddress::Any,33333)){
        qDebug() << "Start";
    }
    else{
        qDebug() << "Error";
    }
    databaseInterface::getInst();
}

void Server::sendToClient(QString msg, QTcpSocket *client)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << msg;
    client->write(data);

}

void Server::sendToClients(QString msg, QStringList UserIDs)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << msg;
    for (auto& n : UserIDs) {
        map[n]->write(data);
    }
}

void Server::messageManager(QString msg, QTcpSocket* client)
{
    QString msgBack;
    QString msgForOthers;
    QStringList members;
    if(msg.startsWith("LOGIN")) {
        QStringList parsedStr = msg.split(" ");
        msgBack = "LOGIN ";
        QString res = databaseInterface::getInst() -> authorize(parsedStr[1],parsedStr[2]);
        msgBack += res;
        if (res == "1") {
            map[databaseInterface::getInst() -> getUserID(parsedStr[1])] = client;
        }

    }
    if (msg.startsWith("REGISTER")) {
        QStringList parsedStr = msg.split(" ");
        msgBack = "REGISTER ";
        QString res = databaseInterface::getInst()->reg(parsedStr[1], parsedStr[2], parsedStr[3], parsedStr[4]);
        msgBack += res;
        if (res == "1"){
            map[databaseInterface::getInst() -> getUserID(parsedStr[1])] = client;
        }
    }
    if(msg.startsWith("LOGOUT")) {
        QStringList parsedStr = msg.split(" ");
        map[parsedStr[1]] = nullptr;
        msgBack = "LOGOUT 1";
    }
    if(msg.startsWith("CREATE")){
        QStringList parsedStr = msg.split(" ");
        QString nick = databaseInterface::getInst() -> create(parsedStr[1],parsedStr[3]);
        QString QID = databaseInterface::getInst() -> getQID(parsedStr[1]);
        msgBack = "CREATE " + parsedStr[1] + " " + nick + " " + QID;
    }
    if(msg.startsWith("GO")){
        QStringList parsedStr = msg.split(" ");
        msgBack = databaseInterface::getInst()->GoToQ(parsedStr[1],parsedStr[3]);
        QString msgForOthers = "NEW " + msgBack.split(" ")[3] + " " + msgBack.split(" ")[4];
        QStringList members = databaseInterface::getInst()->getQMembers(msgBack.split(" ")[1]);
        sendToClients(msgForOthers, members);
    }
    if(msg.startsWith("LEAVE")){
        QStringList parsedStr = msg.split(" ");
        QString msgForOthers = "LEAVE " + databaseInterface::getInst()->leave(parsedStr[1],parsedStr[2]);
        sendToClients(msgForOthers,databaseInterface::getInst()->getQMembers(parsedStr[2]));
    }
    if(!msgBack.isEmpty()) {
        qDebug() << msgBack;
        sendToClient(msgBack,client);
    }
    if(!msgForOthers.isEmpty()) {
        qDebug() << msgForOthers;
        sendToClients(msgForOthers, members);
    }
}


void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket,&QTcpSocket::readyRead,this,&Server::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected,this,&Server::clientDisconnected);
    sockets.push_back(socket);
    qDebug() << "Client connected" << socketDescriptor;

}

void Server::clientDisconnected()
{
    socket = (QTcpSocket*)sender();
    sockets.erase(std::remove(sockets.begin(), sockets.end(), socket), sockets.end());
    for (auto it = map.begin(); it != map.end();){
        if (it.value() == socket){
            it = map.erase(it);
        }
        else{
            ++it;
        }
    }
    socket->deleteLater();
}

void Server::slotReadyRead(){
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok) {
        qDebug() << "read...";
        QString msg;
        in >> msg;
        qDebug() << msg;
        messageManager(msg,socket);

    }
    else{
        qDebug() << "Datastream error";
    }
}

