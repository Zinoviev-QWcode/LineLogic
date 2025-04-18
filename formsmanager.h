#ifndef FORMSMANAGER_H
#define FORMSMANAGER_H

#include <QMainWindow>
#include "authregform.h"
#include "queuehub.h"
#include "queuecreator.h"
#include "queue.h"
class formsManager : public QMainWindow
{
    Q_OBJECT

public:
    formsManager(QWidget *parent = nullptr);
    ~formsManager();


private:
    AuthRegForm * curr_auth; //Окно авторизации и регистрации
    QueueHub * hub; // Окно-меню
    QueueCreator * creator; //Окно для создания очереди
    Queue * q; // Окно очереди
public slots:
    void fromLoginToHub(bool result); //Слот, закрывающий окно авторизации и открывающий меню, если авторизация прошла успешно
    void fromRegToHub(bool result); //Слот, открывающий меню помлн регистрации
    void fromHubToLogin(); //Слот для выхода обратно в окно регистрации
    void fromHubToQ(QString QID, QString Qname, QString nick, QString position, QStringList members);//Слот для открытия окна с очередью
    void fromQToHub();//Слот для выхода из очереди
    void fromHubToCreator();//Слот для перехода в окно для создания очереди
    void fromCreatorToHub();// и обратно
    void fromCreatorToQ(QString name, QString nick, QString QID); //окно для перехода в новосозаднную очередь
    void QUpdate(QString nick, QString position);//Слот, срабатывающий когда в очередь заходит новый пользователь.
    void Qleft(QString position);//Слот, срабатывающий когда пользователь покидает очередь

};
#endif // FORMSMANAGER_H
