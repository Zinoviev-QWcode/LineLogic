#ifndef LOGIC_H
#define LOGIC_H
#include <QString>
#include <QDialog>
//Здесь хедер с функциями для отправки сообщений на сервер
void authorize(QString log, QString password); //авторизация
void reg(QString log, QString nick, QString password, QString mail);//регистрация
void logout();// разлогиниться
void createQ(QString name);//создать очередь
void GoToQ(QString QID);//перейти в очередь
void leaveQ(QString QID);// покинуть очередь



#endif // LOGIC_H
