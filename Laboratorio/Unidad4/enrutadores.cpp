#include "enrutadores.h"

enrutadores::enrutadores()
{

}

enrutadores::enrutadores(char _nombre)
{
    nombre = _nombre;
}


//Metodos getter y setter

char enrutadores::getNombre() const
{
    return nombre;
}

void enrutadores::setNombre(char newNombre)
{
    nombre = newNombre;
}
