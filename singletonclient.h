#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

//Клиент-синглтон для обмена сообщениями с сервером//
class singletonclient;

class singletonDestroyer
{
private:
    singletonclient* p_instance;
public:
    ~singletonDestroyer() {delete p_instance;}
    void init(singletonclient* p) {p_instance = p;}

};

class singletonclient : public QObject
{
    Q_OBJECT
private:
    static singletonclient* p_instance;
    static singletonDestroyer destroyer;
    QTcpSocket* mTcpSocket; //сокет
    QByteArray data;
protected:
    explicit singletonclient(QObject *parent = nullptr);
    singletonclient(singletonclient&) = delete;
    ~singletonclient();
    friend class singletonDestroyer;
public:
    static singletonclient* getInst();
    void sendToServer(QString msg); // Отправка сообщений на сервер
    void messageManager(QString msg); //обработка сообщений от сервера
    QString Username; // Логин авторизованного пользователя (для удобства)
signals:
    void created(QString Qname, QString nick, QString QID);
    void authorizationResult(bool result);
    void registrationResult(bool result);
    void logout();
    void added(QString QID,QString Qname, QString nick, QString position, QStringList members);
    void newInQ(QString nick, QString position);
    void left(QString position);
public slots:
    void slotReadyRead();
};



#endif // SINGLETONCLIENT_H
