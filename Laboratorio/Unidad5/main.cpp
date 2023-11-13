
#include "videojuego.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    videojuego w;
    a.setWindowIcon(QIcon(":/Recursos/Icono/pacman.ico"));
    qSetMessagePattern("%{if-debug}Debug: %{message} %{endif}");
    w.show();
    return a.exec();

}









