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


    //Getter y setter
    char getNombre() const;
    void setNombre(char newNombre);
    void getTablaEnrutamiento();
    void setTablaEnrutamiento(const map<unsigned char, map<unsigned char, int> > &newTablaEnrutamiento);
    void getEnrutadoresVecinos();
    void setEnrutadoresVecinos(const map<unsigned char, map<unsigned char, int> > &newEnrutadoresVecinos);
};

#endif
