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
    map<unsigned char, map<unsigned char, int >> enrutadoresVecinos;

public:

    //Constructores
    enrutador();
    enrutador(char _nombre);
    enrutador(char _nombre, map<unsigned char, map<unsigned char, int >> _tablaEnrutamiento);
    enrutador(char _nombre, map<unsigned char, map<unsigned char, int >> _tablaEnrutamiento,map<unsigned char, map<unsigned char, int >> _enrutadoresVecinos );

    //Metodos
    void cargar_Vecinos(string ruta);
    void mostrar_Enrutamiento();
    void mostrar_EnrutadoresVecinos();

    //Getter y setter
    char getNombre() const;
    void setNombre(char newNombre);
    map<unsigned char, map<unsigned char, int> > getTablaEnrutamiento() const;
    void setTablaEnrutamiento(const map<unsigned char, map<unsigned char, int> > &newTablaEnrutamiento);
    map<unsigned char, map<unsigned char, int> > getEnrutadoresVecinos() const;
    void setEnrutadoresVecinos(const map<unsigned char, map<unsigned char, int> > &newEnrutadoresVecinos);

};

#endif
