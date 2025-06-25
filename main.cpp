#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setGeometry(100, 100, 480, 272);
    mainWindow.show();

    return app.exec();
}
