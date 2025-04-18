#ifndef QUEUEHUB_H
#define QUEUEHUB_H

#include <QDialog>
#include "logic.h"

namespace Ui {
class QueueHub;
}

class QueueHub : public QDialog
{
    Q_OBJECT

public:
    explicit QueueHub(QWidget *parent = nullptr);
    ~QueueHub();
    void clear();

private:
    Ui::QueueHub *ui;
signals:
    void goCreate();//перейти в окно для создания очереди
private slots:
    void on_LogOut_clicked();
    void on_GoToQueue_clicked();
    void on_CreateQueue_clicked();
    void on_lineEdit_QID_textChanged(const QString &arg1);
};

#endif // QUEUEHUB_H
