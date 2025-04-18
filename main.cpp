#include "formsmanager.h"
#include "singletonclient.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    formsManager w;
    return a.exec();
}
