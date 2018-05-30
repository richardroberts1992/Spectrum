#include "mainwindow.h"
#include "colourmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    ColourManager::Init_ColourManager();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
