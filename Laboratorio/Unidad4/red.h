#ifndef RED_H
#define RED_H

#include <iostream>|
#include <string.h>
#include <vector>
#include <list>
#include <fstream>
#include <enrutador.h>
#include <gestorTxt.h>
#include <queue>

using namespace std;

class red
{

private:

    vector<enrutador> vector_Instancias;
    list<char>enrutadores;
    map<unsigned char, map<unsigned char, int >> enrutadores_Vecinos;
    map<unsigned char, map<unsigned char, int >> enrutamiento_Aux;
    map<unsigned char, int> distancias;

public:

    //Constructores
    red();

    //Metodos
    void pruebas();
    void listar_Enrutadores();
    void cargar_Enrutadores(string ruta);
    bool buscarRed(char elemento_Buscado);
    void inicializar_Enrutamiento(string ruta);
    void mostrar_EnrutamientoAuxiliar();
    void mostrar_Vecinos();
    void inicializarDistancias();
    int dijkstra(char nodoInicio, char nodoFinal);
    void gen_Enrutamiento();


};

#endif // RED_H
