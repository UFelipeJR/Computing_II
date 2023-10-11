#include "red.h"

//Constructores

red::red()
{

}


//Metodos

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

void red::cargar_Enrutadores(string ruta)
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
    for(unsigned char elemento : enrutadores){
        if(elemento == elemento_Buscado){
            return true;
        }
    }
    return false;

}


void red::inicializar_Enrutamiento(string ruta)
{
    char elemento;
    enrutador instancia_Auxiliar;
    map<unsigned char, map<unsigned char, int>> vecinos;
    unsigned char enrutadorActual;
    unsigned char vecinoActual;
    int costo;

    const map<unsigned char, int>* vecinosDelEnrutador;

    for (char& elemento : enrutadores) {
        enrutador instancia(elemento);
        vector_Instancias.push_back(instancia);
    }

    enrutadores_Vecinos.clear();

    for (int i = 0; i < vector_Instancias.size(); i++) {
        instancia_Auxiliar = vector_Instancias[i];
        instancia_Auxiliar.cargar_Vecinos(ruta);
        vecinos = instancia_Auxiliar.getEnrutadoresVecinos();

        for (auto& entrada : vecinos) {
            enrutadorActual = entrada.first;
            vecinosDelEnrutador = &entrada.second;

            for (auto& vecino : *vecinosDelEnrutador) {
                vecinoActual = vecino.first;
                costo = vecino.second;

                enrutadores_Vecinos[enrutadorActual][vecinoActual] = costo;
                enrutadores_Vecinos[vecinoActual][enrutadorActual] = costo;
            }
        }
    }
}


void red::mostrar_EnrutamientoAuxiliar()
{
    int valor = 0;

    cout << "Tabla de enrutamiento auxiliar: " << endl;

    for (auto& parExterno : enrutamiento_Aux) {
        for (auto& parInterno : parExterno.second) {
            valor = parInterno.second;
            cout << valor << " ";
        }
        cout << endl;
    }

}

void red::mostrar_Vecinos()
{
    int valor = 0;

    cout << "Tabla de vecinos: " << endl;

    for (auto& parExterno : enrutadores_Vecinos) {
        for (auto& parInterno : parExterno.second) {
            valor = parInterno.second;
            cout << valor << " ";
        }
        cout << endl;
    }
}


void red::inicializarDistancias() {
    for (char nodo : enrutadores) {
        distancias[nodo] = INT_MAX;
    }
}


int red::dijkstra(char nodoInicio, char nodoFinal)
{
    char nodo;
    int distancia;
    char vecino;
    int peso;
    distancias[nodoInicio] = 0;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> siguiente;
    siguiente.push(make_pair(0, nodoInicio));


    while (!siguiente.empty()) {
        nodo = siguiente.top().second;
        distancia = siguiente.top().first;
        siguiente.pop();

        if (nodo != nodoFinal && distancia <= distancias[nodo]) {
            for (const auto& kvp : enrutadores_Vecinos[nodo]) {
                vecino = kvp.first;
                peso = kvp.second;

                if (distancias[vecino] > distancias[nodo] + peso) {
                    distancias[vecino] = distancias[nodo] + peso;
                    siguiente.push(make_pair(distancias[vecino], vecino));
                }
            }
        }
    }

    if (distancias[nodoFinal] == INT_MAX) {
        return -1;
    }

    return distancias[nodoFinal];
}

void red::gen_Enrutamiento()
{

    for(unsigned char elemento1 : enrutadores){
        for(unsigned  char elemento2 : enrutadores){
            inicializarDistancias();
            enrutamiento_Aux[elemento1][elemento2] = dijkstra(elemento1,elemento2);
        }
    }
}


//Metodos getter y setter










