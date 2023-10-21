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
    enrutador(char& _nombre);
    enrutador(char& _nombre, map<unsigned char, map<unsigned char, int >> _tablaEnrutamiento);
    enrutador(char& _nombre, map<unsigned char, map<unsigned char, int >> _tablaEnrutamiento,map<unsigned char, map<unsigned char, int >> _enrutadoresVecinos );

    //Metodos
    void cargar_Vecinos(string& ruta);
    void mostrar_Enrutamiento();
    void mostrar_EnrutadoresVecinos();
    void mostrar_Coste(char& destino);
    void eliminar_Enlace(char& nombre);
    void agregar_Editar_Enlace(char destino,int& costo);

    //Getter y setter
    char getNombre() const;
    void setNombre(char& newNombre);
    map<unsigned char, map<unsigned char, int> > getTablaEnrutamiento() const;
    void setTablaEnrutamiento(const map<unsigned char, map<unsigned char, int> > &newTablaEnrutamiento);
    map<unsigned char, map<unsigned char, int> > getEnrutadoresVecinos() const;
    void setEnrutadoresVecinos(const map<unsigned char, map<unsigned char, int> > &newEnrutadoresVecinos);

    //Metodos complementarios de la clase que no se relacionan con los atributos
    unsigned long long int obtenerLongitud(string& ruta);
    unsigned long long int obtenerLongitud(const vector<unsigned char> &miVector);
    vector<unsigned char> leerArchivo(string& rutaArchivo);
    vector<string>split(const string& entrada, char& delimitador);
    string vector_String(vector<unsigned char>&miVector);
    int caracter_Aleatorio();
    int moneda();
    friend ostream& operator<<(ostream& os, const enrutador& gestor);
};

#endif
