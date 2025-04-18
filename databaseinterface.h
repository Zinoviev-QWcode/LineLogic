#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

//Синглтон для работы с БД//
class databaseInterface;

class interfaceDestroyer{
private:
    databaseInterface* p_instance;
public:
    ~interfaceDestroyer() {delete p_instance;}
    void init(databaseInterface* p) {p_instance = p;}
};

class databaseInterface : public QObject
{
    Q_OBJECT
public:
    QString getUserID(QString login);
    QString getPosition(QString QID);
    QString getQID(QString name);
    QString getNick(QString UserID);
    QString getQName(QString QID);
    QStringList getQMembers(QString QID);
    QString authorize(QString login, QString password);
    QString reg(QString login, QString nick, QString password, QString mail);
    QString create(QString name,QString login);
    QString GoToQ(QString QID, QString User);
    QString leave(QString login, QString QID);
private:
    static databaseInterface* p_instance;
    static interfaceDestroyer destroyer;
    QSqlDatabase db;
    QSqlQuery* query;
protected:
    explicit databaseInterface(QObject *parent = nullptr);
    databaseInterface(databaseInterface&) = delete;
    ~databaseInterface();
    friend class interfaceDestroyer;
public:
    static databaseInterface* getInst();
};

#endif // DATABASEINTERFACE_H
