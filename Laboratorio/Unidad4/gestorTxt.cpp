#include "gestorTxt.h"

//Constructores

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

//Metodos

unsigned long long gestorTxt::obtenerLongitud(const vector<unsigned char> &miVector)
{
    unsigned long long int size = 0;

    while(miVector[size]!='\0'){
        size += 1;
    }
    return size;

}

vector<unsigned char>gestorTxt::leerArchivo(string rutaArchivo)
{
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
        datos.push_back('\0');
    }
    else{
        cout << "Error al leer el archivo";
        return {};
    }

    archivo.close();

    return datos;
}

vector<string> gestorTxt::split(const string &entrada, char delimitador)
{
    vector<string> subcadenas;
    string subcadena;
    int inicio = 0;
    int fin = entrada.find(delimitador);

    while(fin != string::npos){
        subcadena = entrada.substr(inicio,fin-inicio);
        subcadenas.push_back(subcadena);
        inicio = fin + 1;
        fin = entrada.find(delimitador,inicio);

    }

    subcadena = entrada.substr(inicio);
    subcadenas.push_back(subcadena);


    return subcadenas;
}

string gestorTxt::vector_String(vector<unsigned char>&miVector)
{
    gestorTxt archivo;
    string cadena = "";
    unsigned long long int cont_Saltos = 1;

    for(unsigned long long int i = 0; i < miVector.size(); i++){
        if(miVector[i] != ' ' && miVector[i] != '\n'){
            cadena.push_back(miVector[i]);
        }
        else if(miVector[i] == '\n'){
            cont_Saltos ++;
            cadena += " ";
        }
    }

    cadena = cadena.substr(0,cadena.length()-cont_Saltos);

    return cadena;

}


// Sobrecarga de operadores

ostream& operator<<(ostream& os, const vector<unsigned char>& vec)
{
    for (int i = 0; i < vec.size(); ++i) {
        os << vec[i];
    }
    return os;
}

//Metodos getter y setter







