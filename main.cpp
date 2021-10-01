#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow mW;
    mW.show();
    return a.exec();
}
