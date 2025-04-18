#include "databaseinterface.h"
QString databaseInterface::getUserID(QString login)
{
    query->prepare("SELECT user_id FROM users WHERE login = ?;");
    query->addBindValue(login);
    query->exec();
    QString result;
    while(query->next()) {
        result = query->value(0).toString();
    }
    return result;
}

QString databaseInterface::getPosition(QString QID)
{
    query->prepare("SELECT COUNT(*) + 1 FROM queue_entries WHERE queue_id = ?");
    query->addBindValue(QID);
    query->exec();
    QString result;
    while(query->next()) {
        result = query->value(0).toString();
    }
    return result;
}

QString databaseInterface::getQID(QString name)
{
    query->prepare("SELECT queue_id FROM queues WHERE queue_name = ?;");
    query->addBindValue(name);
    query->exec();
    QString result;
    while(query->next()) {
        result = query->value(0).toString();
    }
    return result;
}

QString databaseInterface::getNick(QString UserID)
{
    QString nick;
    query->prepare("SELECT nickname from users WHERE user_id = ?");
    query->addBindValue(UserID);
    query->exec();
    while(query->next()) {
        nick = query->value(0).toString();
    }
    return nick;
}

QString databaseInterface::getQName(QString QID)
{
    QString name;
    query->prepare("SELECT queue_name from queues WHERE queue_id = ?");
    query->addBindValue(QID);
    query->exec();
    while(query->next()) {
        name = query->value(0).toString();
    }
    return name;
}

QStringList databaseInterface::getQMembers(QString QID)
{
    QStringList members;
    query->prepare("SELECT user_id from queue_entries WHERE queue_id = ? ORDER BY position ASC LIMIT 10");
    query->addBindValue(QID);
    query->exec();
    while(query->next()) {
        members.append(query->value(0).toString());
    }
    return members;
}

QString databaseInterface::authorize(QString login, QString password)
{
    query->prepare("SELECT COUNT(*) FROM users WHERE login = ? AND password = ?;");
    query->addBindValue(login);
    query->addBindValue(password);
    query->exec();
    QString result;
    while(query->next()) {
        result = query->value(0).toString();
    }
    return result;
}

QString databaseInterface::reg(QString login, QString nick, QString password, QString mail)
{
    query->prepare("INSERT INTO users(login,password,nickname,email) VALUES(?,?,?,?);");
    query->addBindValue(login);
    query->addBindValue(password);
    query->addBindValue(nick);
    query->addBindValue(mail);
    QString result = (query->exec() ? "1" : "0");
    return result;
}

QString databaseInterface::create(QString name, QString login)
{
    query->prepare("INSERT INTO queues(queue_name, status) VALUES(?,1)");
    query->addBindValue(name);
    query->exec();
    QString QID = getQID(name);
    QString userID = getUserID(login);
    QString nick;
    query->prepare("INSERT INTO queue_entries(queue_id,user_id,position) VALUES(?,?,1)");
    query->addBindValue(QID);
    query->addBindValue(userID);
    query->exec();
    nick = getNick(getUserID(login));
    return nick;

}

QString databaseInterface::GoToQ(QString QID, QString User)
{
    query->prepare("SELECT COUNT(*) from queues WHERE queue_id = ?");
    query->addBindValue(QID);
    query->exec();
    QString doesExist;
    while(query->next()) {
        doesExist = query->value(0).toString();
    }
    if (doesExist == "1") {
        QString userID = getUserID(User);
        QString position = getPosition(QID);
        QStringList members_nicks = getQMembers(QID);
        for (auto& n:members_nicks) {
            n = getNick(n);
        }
        query->prepare("INSERT INTO queue_entries(queue_id,user_id,position) VALUES(?,?,?);");
        query->addBindValue(QID); query->addBindValue(userID); query->addBindValue(position);
        query->exec();
        QString msg;
        QString nick = getNick(getUserID(User));
        QString Qname = getQName(QID);
        msg = "ADDED " + QID + " " + Qname + " " + nick + " " + position + " MEMBERS " + members_nicks.join(" ");
        return msg;
    }
    else{
        return "Error 0 0 0 0";
    }

}

QString databaseInterface::leave(QString login, QString QID)
{
    QString position;
    QString UserId = getUserID(login);
    qDebug()<<UserId;
    query->prepare("SELECT position from queue_entries WHERE user_id = ?;");
    query->addBindValue(UserId);
    qDebug()<<query->exec();
    while(query->next()) {
        position = query->value(0).toString();
    }
    qDebug()<<position;
    query->prepare("DELETE from queue_entries where user_id = ?");
    query->addBindValue(UserId);
    query->exec();
    query->prepare("UPDATE queue_entries SET position = position - 1 WHERE position > ? and queue_id = ?;");
    query->addBindValue(position);
    query->addBindValue(QID);
    query->exec();
    return position;
}

databaseInterface::databaseInterface(QObject *parent)
    : QObject{parent}
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./database.db");
    if(db.open()) {
        qDebug("open");
    }
    else{
        qDebug("DB error");
    }

    query = new QSqlQuery(db);
    qDebug() << (query->exec("CREATE TABLE IF NOT EXISTS users(user_id INTEGER PRIMARY KEY AUTOINCREMENT, login VARCHAR(50) NOT NULL UNIQUE, password VARCHAR(255) NOT NULL, nickname VARCHAR(100), email VARCHAR(100) UNIQUE);") ? "succes" : "fail");
    qDebug() << (query->exec("CREATE TABLE IF NOT EXISTS queues(queue_id INTEGER PRIMARY KEY AUTOINCREMENT, queue_name VARCHAR(100) NOT NULL, status INTEGER);") ? "succes" : "fail") ;
    qDebug() << (query->exec("CREATE TABLE IF NOT EXISTS queue_entries(entry_id INTEGER PRIMARY KEY AUTOINCREMENT, queue_id INT NOT NULL, user_id INT NOT NULL, position INT NOT NULL, FOREIGN KEY (queue_id) REFERENCES queues(queue_id), FOREIGN KEY (user_id) REFERENCES users(user_id));") ? "succes" : "fail");
}

databaseInterface::~databaseInterface()
{
    if (db.isOpen()) {
        db.close();
    }
}

databaseInterface *databaseInterface::getInst()
{
    if (!p_instance) {
        p_instance = new databaseInterface();
        destroyer.init(p_instance);
    }
    return p_instance;
}

databaseInterface* databaseInterface::p_instance;
interfaceDestroyer databaseInterface::destroyer;
