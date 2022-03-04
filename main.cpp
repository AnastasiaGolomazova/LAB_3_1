#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainwindow;
    mainwindow.show();
    mainwindow.select_folder("../TEST/");
    return a.exec();
}

