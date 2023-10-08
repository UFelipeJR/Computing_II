#include "enrutador.h"
#include "gestorTxt.h"

//Constructores

enrutador::enrutador()
{

}

enrutador::enrutador(char _nombre)
{
    nombre = _nombre;
}

enrutador::enrutador(char _nombre, map<unsigned char, map<unsigned char, int >> _tablaEnrutamiento)
{
    nombre = _nombre;
    tablaEnrutamiento = _tablaEnrutamiento;
}





//Metodos

void enrutador::extraer_Enrutamiento(string ruta){

    gestorTxt archivo;

    string cadena_Aux = "";
    string enrutamiento_Auxiliar = "";

    vector<unsigned char> informacion_Archivo = archivo.leerArchivo(ruta);
    vector<string> informacion_Split;

    char nombre = getNombre();

    unsigned long long int contSaltos = 0;
    unsigned long long int size = archivo.obtenerLongitud(informacion_Archivo);
    unsigned int size_Temporal = 0;

    for(unsigned long long int i = 0; i < size; i++){
        if(informacion_Archivo[i] != ' ' && informacion_Archivo[i] != '\n'){
            cadena_Aux += informacion_Archivo[i];
        }
        if(informacion_Archivo[i] == '\n'){
            contSaltos += 1;
            cadena_Aux += " ";
        }
    }
    size = cadena_Aux.length();
    cadena_Aux = cadena_Aux.substr(0,size-contSaltos);
    informacion_Split = archivo.split(cadena_Aux, ' ');

    for(int i = 0; i < informacion_Split.size();i++){
        if(informacion_Split[i][0] == nombre || informacion_Split[i][1] == nombre){
            tablaEnrutamiento[informacion_Split[i][0]][informacion_Split[i][1]] = stoi(informacion_Split[i].substr(2,informacion_Split[i].length()-2));
        }

    }

}

//Metodos getter y setter

char enrutador::getNombre() const
{
    return nombre;
}

void enrutador::setNombre(char newNombre)
{
    nombre = newNombre;
}

void enrutador::getTablaEnrutamiento()
{
    int valor = 0;

    for (auto& parExterno : tablaEnrutamiento) {
        for (auto& parInterno : parExterno.second) {
            valor = parInterno.second;
            cout << valor << " ";
        }
        cout << endl;
    }

}

void enrutador::setTablaEnrutamiento(const map<unsigned char, map<unsigned char, int> > &newTablaEnrutamiento)
{
    tablaEnrutamiento = newTablaEnrutamiento;
}
