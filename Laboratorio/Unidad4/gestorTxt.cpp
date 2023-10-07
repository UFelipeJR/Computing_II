#include "gestorTxt.h"

gestorTxt::gestorArchivos()
{

}

unsigned long long int gestorTxt::obtenerLongitud(string ruta)
{
    unsigned long long int size = 0;
    fstream archivo;

    archivo.open(ruta,ios::in | ios::ate);
    if(archivo.is_open()){
        size = archivo.tellg();
        archivo.close();
        return size;
    }
    else{
        cout << "Error al leer el archivo: ";
        return 1;
    }

}

vector<unsigned char>gestorTxt::leerArchivo(string rutaArchivo){

    fstream archivo;
    unsigned long long int size = 0;
    vector<unsigned char> datos;

    archivo.open(rutaArchivo,ios::in|ios::ate);


    if(archivo.is_open()){
        size = obtenerLongitud(rutaArchivo);
        datos.reserve(size);
        archivo.seekg(0);
        for(unsigned long long i = 0; i < size; i++){
            datos.push_back(static_cast<unsigned char>(archivo.get()));
        }
    }
    else{
        cout << "Error al leer el archivo";
        return {};
    }

    archivo.close();

    return datos;
}












