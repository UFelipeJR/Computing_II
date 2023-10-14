#include "red.h"

//Constructores

red::red()
{

}


//Metodos

void red::pruebas() {

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
    enrutador archivo;
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

void red::generar_VectorInstancias()
{
    for (char& elemento : enrutadores) {
        enrutador instancia(elemento);
        vector_Instancias.push_back(instancia);
    }

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

    generar_VectorInstancias();
    enrutadores_Vecinos.clear();

    for (unsigned long long int i = 0; i < vector_Instancias.size(); i++) {
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

void red::inicializar_Enrutamiento()
{
    char elemento;
    enrutador instancia_Auxiliar;
    map<unsigned char, map<unsigned char, int>> vecinos;
    unsigned char enrutadorActual;
    unsigned char vecinoActual;
    int costo;

    const map<unsigned char, int>* vecinosDelEnrutador;

    generar_VectorInstancias();
    enrutadores_Vecinos.clear();

    for (unsigned long long int i = 0; i < vector_Instancias.size(); i++) {
        instancia_Auxiliar = vector_Instancias[i];
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
    unsigned long long int valor = 0;

    cout << "Tabla de enrutamiento auxiliar: " << endl;

    for (auto& parExterno : enrutamiento_Aux) {
        for (auto& parInterno : parExterno.second) {
            valor = parInterno.second;
            if(valor == ULLONG_MAX){
                cout << -1 << " ";
            }
            else{
                cout << valor << " ";
            }


        }
        cout << endl;
    }

}

void red::mostrar_Vecinos()
{
    unsigned long long int valor = 0;

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
    for (unsigned char nodo : enrutadores) {
        distancias[nodo] = ULLONG_MAX;
    }
}


unsigned long long int red::dijkstra(char nodoInicio, char nodoFinal)
{
    unsigned char nodo;
    unsigned long long int distancia;
    unsigned char vecino;
    unsigned long long int peso;
    distancias[nodoInicio] = 0;
    priority_queue<pair<unsigned long long int, char>, vector<pair<unsigned long long int, char>>, greater<pair<unsigned long long int, char>>> siguiente;
    siguiente.push(make_pair(0, nodoInicio));


    while (!siguiente.empty()) {
        nodo = siguiente.top().second;
        distancia = siguiente.top().first;
        siguiente.pop();

        if (nodo != nodoFinal && distancia <= distancias[nodo]) {
            for (auto& kvp : enrutadores_Vecinos[nodo]) {
                vecino = kvp.first;
                peso = kvp.second;

                if (distancias[vecino] > distancias[nodo] + peso) {
                    distancias[vecino] = distancias[nodo] + peso;
                    siguiente.push(make_pair(distancias[vecino], vecino));
                }
            }
        }
    }

    if(distancias[nodoFinal] == ULLONG_MAX){
        return -1;
    }

    return distancias[nodoFinal];



}

void red::gen_Enrutamiento()
{
    for(unsigned char elemento1 : enrutadores){
        for(unsigned char elemento2 : enrutadores){
            inicializarDistancias();
            enrutamiento_Aux[elemento1][elemento2] = dijkstra(elemento1,elemento2);
        }
    }
}

void red::actualizar_Enrutadores()
{

    if (vector_Instancias.empty()) {
        cout << "El vector está vacío" << endl;
    }
    else {
        for (int i = 0; i < vector_Instancias.size(); i++) {
            vector_Instancias.at(i).setTablaEnrutamiento(enrutamiento_Aux);
        }
    }
}

void red::generar_ListaAleatoria(int n)
{
    enrutadores.clear();
    enrutador val;
    int i = 0;
    int caracter = 0;
    while(i != n){
        caracter = val.caracter_Aleatorio();
        if(buscarRed(char(caracter)) == 0){
            enrutadores.push_back(char(caracter));
            i ++;
        }
    }
}

int red::determinar_Existencia(float k)
{
    enrutador val;
    int numeroRandom = 0;
    int costeAleatorio = rand() % 101;


    for (list<char>::iterator it = enrutadores.begin(); it != enrutadores.end(); ++it) {
        numeroRandom = val.moneda();
        if (numeroRandom < k) {
            return costeAleatorio;
        } else {
            return -1;
        }
    }
    return 0;

}

int red::buscar_Instancia(char &nombre)
{
    enrutador aux;
    for (int i = 0; i < vector_Instancias.size(); i++) {
        aux = vector_Instancias.at(i);
        if (aux.getNombre() == nombre) {
            return i;
        }
    }

    return -1;
}


void red::generar_GrafoAleatorio(int n, float k)
{

    vector_Instancias.clear();
    map<unsigned char, map<unsigned char, int >> enrutadores_Adyacentes;
    generar_ListaAleatoria(n);
    generar_VectorInstancias();
    int existencia = 0;
    int pos = 0;

    for (list<char>::iterator it0 = enrutadores.begin(); it0 != enrutadores.end(); ++it0) {
        for (list<char>::iterator it1 = enrutadores.begin(); it1 != enrutadores.end(); ++it1) {
            existencia = determinar_Existencia(k);
            pos = buscar_Instancia(*it0);
            if(existencia != -1){
                enrutadores_Adyacentes[*it0][*it1] = existencia;
            }
        }
        vector_Instancias.at(pos).setEnrutadoresVecinos(enrutadores_Adyacentes);
        enrutadores_Adyacentes.clear();
    }


}

//Metodos getter y setter

    /*
    for (list<char>::iterator it = enrutadores.begin(); it != enrutadores.end(); ++it) {
        cout << *it << endl;
    }
    */


    /*
    for (list<char>::iterator it = enrutadores.begin(); it != enrutadores.end(); ++it) {
        numeroRandom = static_cast<double>(val.moneda());

            if (numeroRandom < k) {
                cout << "El enlace existe." << endl;
            } else {
                cout << "El enlace no existe." << endl;
            }
        //cout << *it << endl;

        //validar que no hayan enlaces aleatorios ya que existe margen de que salgan caracteres repetidos
        //Cambiar los tipos de datos de las variables unsigned long long int a unsigned int
        //comentar todo antes de que nos dé pereza
    }
    */

    /*
    for (vector<enrutador>::iterator it = vector_Instancias.begin(); it != vector_Instancias.end(); ++it) {
        cout << (*it).getNombre() << " ";
    }
    cout << endl;
    */

    /*
    for(unsigned char elemento1 : enrutadores){
        for(unsigned char elemento2 : enrutadores){
            cout << elemento1 << " " << elemento2 << endl;
        }
    }
    */


