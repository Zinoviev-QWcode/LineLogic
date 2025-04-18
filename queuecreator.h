#ifndef QUEUECREATOR_H
#define QUEUECREATOR_H

#include <QDialog>

namespace Ui {
class QueueCreator;
}

class QueueCreator : public QDialog
{
    Q_OBJECT

public:
    explicit QueueCreator(QWidget *parent = nullptr);
    ~QueueCreator();
    void clear(); //очищает поле
signals:
    void GoBack(); //возвращает обратно в меню
private slots:
    void on_Cancel_clicked();

    void on_Create_clicked();

    void on_QueueName_textChanged(const QString &arg1);

private:
    Ui::QueueCreator *ui;
};

#endif // QUEUECREATOR_H
