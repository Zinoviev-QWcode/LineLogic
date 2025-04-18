#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include "databaseinterface.h"
#include <QMap>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    QTcpSocket *socket;
private:
    QVector<QTcpSocket*> sockets; //Вектор в котором хранятся ссылки на сокеты для подключения множества клиентов
    QMap<QString,QTcpSocket*> map; // Мапа хранящая пары ID-пользователя|сокет (для удобства)
    QByteArray data;
    void sendToClient(QString msg,QTcpSocket* client); //отправить сообщение одному клиенту
    void sendToClients(QString msg, QStringList UserIDs); //отправить нескольким
    void messageManager(QString msg, QTcpSocket* client);// обработка сообщений с клиента
public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
    void clientDisconnected();
};

#endif // SERVER_H
