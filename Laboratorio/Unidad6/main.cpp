#include "simulation.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    std::srand(std::time(0));
    QApplication a(argc, argv);
    simulation w;
    w.show();
    return a.exec();
}

