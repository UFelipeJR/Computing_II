#ifndef RED_H
#define RED_H

#include <iostream>|
#include <string.h>
#include <vector>
#include <list>
#include <fstream>
#include <enrutador.h>
#include <gestorTxt.h>

using namespace std;

class red
{

private:

    vector<enrutador> vector_Instancias;
    list<char>enrutadores;

public:

    //Constructores
    red();

    //Metodos
    void pruebas();
    void listar_Enrutadores();
    void lista_Enrutadores(string ruta);
    bool buscarRed(char elemento_Buscado);

};

#endif // RED_H
