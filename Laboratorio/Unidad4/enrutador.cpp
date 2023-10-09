#include "enrutador.h"
#include "gestorTxt.h"

//Constructores

enrutador::enrutador()
{

}

enrutador::enrutador(char _nombre)
{
    nombre = _nombre;
}

enrutador::enrutador(char _nombre, map<unsigned char, map<unsigned char, int >> _tablaEnrutamiento)
{
    nombre = _nombre;
    tablaEnrutamiento = _tablaEnrutamiento;
}


//Metodos



//Metodos getter y setter

char enrutador::getNombre() const
{
    return nombre;
}

void enrutador::setNombre(char newNombre)
{
    nombre = newNombre;
}


void enrutador::getTablaEnrutamiento()
{
    int valor = 0;

    for (auto& parExterno : tablaEnrutamiento) {
        for (auto& parInterno : parExterno.second) {
            valor = parInterno.second;
            cout << valor << " ";
        }
        cout << endl;
    }

}

void enrutador::setTablaEnrutamiento(const map<unsigned char, map<unsigned char, int> > &newTablaEnrutamiento)
{
    tablaEnrutamiento = newTablaEnrutamiento;
}
