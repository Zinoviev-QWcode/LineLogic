#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

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
    QTcpSocket* mTcpSocket;
protected:
    explicit singletonclient(QObject *parent = nullptr);
    singletonclient(singletonclient&) = delete;
    ~singletonclient();
    friend class singletonDestroyer;
public:
    static singletonclient* getInst();
    QByteArray sendmsgtoServer(QString query);
signals:
    void messagefromServer(QString msg);
private slots:
    void slotServerRead();
};



#endif // SINGLETONCLIENT_H
