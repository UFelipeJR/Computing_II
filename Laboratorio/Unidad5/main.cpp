#include <videojuego.h>
#include <QApplication>
#include <recursos.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    videojuego w;
    a.setWindowIcon(QIcon(recursos::icoN));
    w.show();
    return a.exec();

}









