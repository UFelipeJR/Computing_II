#ifndef GESTORTXT_H
#define GESTORTXT_H


#include <iostream>|
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;


ostream& operator<<(ostream& os, const vector<unsigned char>& vec);

class gestorTxt
{

private:

public:
    gestorArchivos();
    unsigned long long int obtenerLongitud(string ruta);
    vector<unsigned char> leerArchivo(string rutaArchivo);

    friend std::ostream& operator<<(std::ostream& os, const gestorTxt& gestor);
};


ostream& operator<<(ostream& os, const gestorTxt& gestor);

#endif // GESTORTXT_H
