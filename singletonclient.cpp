#include "singletonclient.h"

singletonclient::singletonclient(QObject *parent)
    : QObject{parent}
{
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket->connectToHost("127.0.0.1", 33333);
    mTcpSocket->waitForReadyRead();
    QByteArray arr;
    while (mTcpSocket->bytesAvailable()>0) {
        arr.append(mTcpSocket->readAll());
    }
    qDebug()<<arr;
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

QByteArray singletonclient::sendmsgtoServer(QString query) {
    mTcpSocket->write(query.toUtf8());
    mTcpSocket->waitForReadyRead();
    QByteArray arr;
    while (mTcpSocket->bytesAvailable()>0)
    {
        arr.append(mTcpSocket->readAll());
    }
    qDebug()<<arr;
    return arr;
}

void singletonclient::slotServerRead(){
    QString msg = "";
    while(mTcpSocket->bytesAvailable()>0){
        QByteArray array = mTcpSocket->readAll();
        msg.append(array);
    }
    qDebug()<<msg;
    emit messagefromServer(msg);

}

singletonclient* singletonclient::p_instance;
singletonDestroyer singletonclient::destroyer;

