#include "enrutador.h"

//Constructores

enrutador::enrutador()
{

}

enrutador::enrutador(char& _nombre)
{
    nombre = _nombre;
}

enrutador::enrutador(char& _nombre, map<unsigned char, map<unsigned char, int >> _tablaEnrutamiento)
{
    nombre = _nombre;
    tablaEnrutamiento = _tablaEnrutamiento;
}

enrutador::enrutador(char& _nombre, map<unsigned char, map<unsigned char, int> > _tablaEnrutamiento, map<unsigned char, map<unsigned char, int> > _enrutadoresVecinos)
{
    nombre = _nombre;
    tablaEnrutamiento = _tablaEnrutamiento;
    enrutadoresVecinos = _enrutadoresVecinos;
}

//Metodos

void enrutador::cargar_Vecinos(string& ruta)
{
    char aux = ' ';
    enrutador archivo;
    vector<unsigned char> informacion_Archivo = archivo.leerArchivo(ruta);
    vector<string> informacion_Split;
    string cadenaAuxiliar = "";
    char nombre = getNombre();

    cadenaAuxiliar = archivo.vector_String(informacion_Archivo);
    informacion_Split = archivo.split(cadenaAuxiliar,aux);



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

void enrutador::mostrar_Coste(char& destino)
{
    cout << tablaEnrutamiento[this->nombre][destino] << endl;

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

void enrutador::eliminar_Enlace(char& nombre)
{
    enrutadoresVecinos[this->nombre].erase(nombre);
    //Falta validar la existencia
}

void enrutador::agregar_Editar_Enlace(char destino, int& costo)
{
    enrutadoresVecinos[nombre][destino] = costo;
}


//Metodos complementarios de la clase que no se relacionan con los atributos

unsigned long long int enrutador::obtenerLongitud(string& ruta)
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

unsigned long long enrutador::obtenerLongitud(const vector<unsigned char> &miVector)
{
    unsigned long long int size = 0;

    while(miVector[size]!='\0'){
        size += 1;
    }
    return size;

}

vector<unsigned char>enrutador::leerArchivo(string& rutaArchivo)
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

vector<string> enrutador::split(const string &entrada, char& delimitador)
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

string enrutador::vector_String(vector<unsigned char>&miVector)
{
    enrutador archivo;
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

int enrutador::caracter_Aleatorio()
{
    int numeroAleatorio = 0;
    do {
        numeroAleatorio = rand() % 58 + 65;
    } while (numeroAleatorio > 90 && numeroAleatorio < 97);

    return numeroAleatorio;
}

int enrutador::moneda()
{
    int numeroAleatorio = rand() % 2;

    return numeroAleatorio;
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

char enrutador::getNombre() const
{
    return nombre;
}

void enrutador::setNombre(char& newNombre)
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







