#ifndef RED_H
#define RED_H

#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <fstream>
#include <enrutador.h>
#include <gestorTxt.h>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

class red
{

/*
 * Clase red
 *
 * Atributos:
 * vector_Instancias: Vector que almacena los enrutadores pertenecientes a la clase con el mismo nombre.
 * enrutadores: Lista con los nombres de los enrutadores activos en la red.
 * enrutadores_vecinos: Mapa con todos los enrutadores que tienen conexión directa con sus respectivos costos.
 * enrutamiento_Aux: Tabla de enrutamiento con todos los costes cálculados.
 * distancias: Mapa en el que se guardan las distancias correspondientes a los enlaces.
 */

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
    unsigned long long int dijkstra(char nodoInicio, char nodoFinal);
    void gen_Enrutamiento();
    void actualizar_Enrutadores();
    void generar_GrafoAleatorio(int n, float k);
    void generar_ListaAleatoria(int n);
    void generar_VectorInstancias();
    int determinar_Existencia(int n, float k);
    //Faltan getter y setter


};

#endif // RED_H
