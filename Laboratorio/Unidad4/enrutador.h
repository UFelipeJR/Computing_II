#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>|
#include <string.h>
#include <vector>
#include <fstream>
#include <map>
using namespace std;


class enrutador
{
private:
    char nombre = ' ';
    map<unsigned char, map<unsigned char, int >> tablaEnrutamiento;

public:

    //Constructores
    enrutador();
    enrutador(char _nombre);
    enrutador(char _nombre, map<unsigned char, map<unsigned char, int >> _tablaEnrutamiento);

    //Metodos
    void extraer_Enrutamiento(string ruta);
    void mostrar_Costo(char nodo1, char nodo2);

    //Getter y setter
    char getNombre() const;
    void setNombre(char newNombre);
    void getTablaEnrutamiento();
    void setTablaEnrutamiento(const map<unsigned char, map<unsigned char, int> > &newTablaEnrutamiento);
};

#endif
