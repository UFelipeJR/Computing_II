#include "red.h"

red::red()
{

}

void red::pruebas()
{


    /*
    char letra = 65;
    for(unsigned long long i = 0; i < n; i++){
        enrutador instanciaAux(letra);
        vector_Instancias.push_back(instanciaAux);
        letra ++;
    }

    listar_Enrutadores();
    */
}


void red::listar_Enrutadores()
{
    unsigned long long int i = 0;
    for(unsigned char elemento : enrutadores){
        cout << "Enrutador " << i+1 << ": "<< elemento << endl;
        i++;
    }
}

void red::lista_Enrutadores(string ruta)
{
    gestorTxt archivo;
    vector<unsigned char> informacion = archivo.leerArchivo(ruta);
    vector<string> informacion_split;
    string cadenaAux = archivo.vector_String(informacion);

    informacion_split = archivo.split(cadenaAux,' ');

    for(unsigned long long int i = 0; i < informacion_split.size(); i++){

        if(buscarRed(informacion_split[i][0]) == 0){
            enrutadores.push_back(informacion_split[i][0]);
        }
        if(buscarRed(informacion_split[i][1]) == 0){
            enrutadores.push_back(informacion_split[i][1]);
        }
    }

    // En base a la longitud de la lista sabremos cuantas instancias de la clase enrutador se deben crear


}

bool red::buscarRed(char elemento_Buscado)
{
    for(unsigned long long int elemento : enrutadores){
        if(elemento == elemento_Buscado){
            return true;
        }
    }
    return false;

}










