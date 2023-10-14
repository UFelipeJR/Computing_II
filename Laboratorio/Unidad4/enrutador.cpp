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

enrutador::enrutador(char _nombre, map<unsigned char, map<unsigned char, int> > _tablaEnrutamiento, map<unsigned char, map<unsigned char, int> > _enrutadoresVecinos)
{
    nombre = _nombre;
    tablaEnrutamiento = _tablaEnrutamiento;
    enrutadoresVecinos = _enrutadoresVecinos;
}

//Metodos

void enrutador::cargar_Vecinos(string ruta)
{
    gestorTxt archivo;

    vector<unsigned char> informacion_Archivo = archivo.leerArchivo(ruta);
    vector<string> informacion_Split;
    string cadenaAuxiliar = "";
    char nombre = getNombre();

    cadenaAuxiliar = archivo.vector_String(informacion_Archivo);
    informacion_Split = archivo.split(cadenaAuxiliar,' ');



    for(unsigned long long int i = 0; i <informacion_Split.size(); i++){
        if(informacion_Split[i][0] == nombre){
            enrutadoresVecinos[informacion_Split[i][0]][informacion_Split[i][1]] = stoll(informacion_Split[i].substr(2,informacion_Split[i].length()-2));
        }

    }
}

void enrutador::mostrar_EnrutadoresVecinos()
{
    int valor = 0;

    for (auto& parExterno : enrutadoresVecinos) {
        for (auto& parInterno : parExterno.second) {
            valor = parInterno.second;
            cout << valor << " ";
        }
        cout << endl;
    }

}

void enrutador::mostrar_Coste(char destino)
{
    cout << tablaEnrutamiento[getNombre()][destino] << endl;

}

void enrutador::mostrar_Enrutamiento()
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

//Metodos getter y setter

char enrutador::getNombre() const
{
    return nombre;
}

void enrutador::setNombre(char newNombre)
{
    nombre = newNombre;
}

map<unsigned char, map<unsigned char, int> > enrutador::getTablaEnrutamiento() const
{
    return tablaEnrutamiento;
}

map<unsigned char, map<unsigned char, int> > enrutador::getEnrutadoresVecinos() const
{
    return enrutadoresVecinos;
}

void enrutador::setTablaEnrutamiento(const map<unsigned char, map<unsigned char, int> > &newTablaEnrutamiento)
{
    tablaEnrutamiento = newTablaEnrutamiento;
}

void enrutador::setEnrutadoresVecinos(const map<unsigned char, map<unsigned char, int> > &newEnrutadoresVecinos)
{
    enrutadoresVecinos = newEnrutadoresVecinos;
}

