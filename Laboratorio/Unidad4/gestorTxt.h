#ifndef GESTORTXT_H
#define GESTORTXT_H


#include <iostream>|
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;

class gestorTxt
{

private:

public:
    gestorArchivos();
    unsigned long long int obtenerLongitud(string ruta);
    vector<unsigned char> leerArchivo(string rutaArchivo);
    void imprimirVector(const vector<unsigned char>& vec);
};




#endif // GESTORTXT_H
