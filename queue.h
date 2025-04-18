#ifndef QUEUE_H
#define QUEUE_H

#include <QDialog>
#include <QVector>
#include <QLabel>

namespace Ui {
class Queue;
}

class Queue : public QDialog
{
    Q_OBJECT

public:
    explicit Queue(QWidget *parent = nullptr);
    ~Queue();
    void QMaker(QString);// функция показывает имя очереди
    void Qfiller(QString nick, int position); //функция заполняет блоки никами пользователей
    void setQID(QString QID);// показывает QID в правом нижнем углe экрана
    void setPosition(QString pos); //показывает место пользователя в очереди
    QString getPosition(); //возвращает место в очереди
    void update(QString position); //смещает вверх пользователей после ухода кого-то
    void clear(); //очищает окно

signals:
    void GoBack(); //сигнал для перехода обратно в меню
private slots:
    void on_pushButton_clicked(); //слот для кнопки

private:
    Ui::Queue *ui;
    QList<QLabel*> labels;

};

#endif // QUEUE_H
