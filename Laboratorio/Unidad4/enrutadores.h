#ifndef ENRUTADORES_H
#define ENRUTADORES_H

#include <iostream>|
#include <string.h>
#include <vector>

using namespace std;


class enrutadores
{
private:
    char nombre;

public:
    enrutadores();
    enrutadores(char _nombre);
    char getNombre() const;
    void setNombre(char newNombre);
};

#endif
