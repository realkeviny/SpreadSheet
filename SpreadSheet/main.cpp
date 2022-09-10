#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSplashScreen* splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/Icon/AMG.jfif"));
    splash->show();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

    splash->showMessage(QObject::tr("Setting Up Main Window..."),topRight,Qt::white);
    MainWindow mainWin;

    splash->showMessage(QObject::tr("Loading Modules..."),topRight,Qt::white);

    splash->showMessage(QObject::tr("Establishing Connections..."));
    

    mainWin.show();
    splash->finish(&mainWin);
    delete splash;

    return app.exec();
}
