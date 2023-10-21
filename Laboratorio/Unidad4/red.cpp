#include "red.h"

//Constructores

red::red()
{

}


//Metodos

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
    char aux = ' ';
    enrutador archivo;
    vector<unsigned char> informacion = archivo.leerArchivo(ruta);
    vector<string> informacion_split;
    string cadenaAux = archivo.vector_String(informacion);

    informacion_split = archivo.split(cadenaAux,aux);

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
    //enrutadores_Vecinos.clear();

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
    //enrutadores_Vecinos.clear();

    for (int i = 0; i < vector_Instancias.size(); i++) {
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
            if(valor == INT_MAX){
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
        distancias[nodo] = INT_MAX;
    }
}


int red::dijkstra(char nodoInicio, char nodoFinal) {

    unsigned char nodo;
    unsigned long long int distancia;
    unsigned char vecino;
    string camino = "";
    char nodoActual;
    unsigned long long int peso;

    priority_queue<pair<unsigned long long int, char>, vector<pair<unsigned long long int, char>>, greater<pair<unsigned long long int, char>>> siguiente;
    map<char, char> padres;

    siguiente.push(make_pair(0, nodoInicio));
    distancias[nodoInicio] = 0;
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
                    padres[vecino] = nodo;
                }
            }
        }
    }

    /*
    nodoActual = nodoFinal;
    while (nodoActual != nodoInicio) {
        camino = nodoActual + camino;
        nodoActual = padres[nodoActual];
    }
    camino = nodoInicio + camino;
    mapa_Caminos[nodoInicio][nodoFinal] = camino;
    */

    //PULIR CALCULO DE RUTAS


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
        cout << "El vector esta vacio" << endl;
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


    for(list<char>::iterator it = enrutadores.begin(); it != enrutadores.end(); ++it){
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

void red::eliminar_Instancia(char& nombre)
{
    int pos = buscar_Instancia(nombre);
    list<char>::iterator it = enrutadores.begin();

    for (list<char>::iterator it0 = enrutadores.begin(); it0 != enrutadores.end(); ++it0) {
        for (list<char>::iterator it1 = enrutadores.begin(); it1 != enrutadores.end(); ++it1) {
            if (char(*it0) == nombre || char(*it1) == nombre) {
                enrutadores_Vecinos[*it0].erase(*it1);
            }
        }
    }

    vector_Instancias.erase(vector_Instancias.begin()+pos);
    advance(it,pos);
    enrutadores.erase(it);

    cout << "Se ha eliminado el enrutador " << nombre << endl;

}


template<typename T>
T red::obtener_Entrada(string mensaje, T inf, T max)
{
    T opcion;

    while (true) {
        cout << mensaje;
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "La entrada no es valida. Debe ser un numero." << endl;
        }
        else if (opcion >= inf && opcion <= max) {
            break;
        }
        else {
            cout << "Opción invalida" << endl;
        }
    }

    return opcion;
}


void red::menu(string ruta)
{
    int opcion = 0;
    int costoAux = 0;
    int enrutadorDestino = 0;
    float probabilidad = 0;
    char aux;
    map<unsigned char, map<unsigned char, int >> adyacentes_Aux;

    do {
        cout << "Menu Principal" << endl;
        cout << "1. Cargar Red Desde Un Archivo" << endl;
        cout << "2. Generar y Visualizar Tabla de Enrutamiento" << endl;
        cout << "3. Agregar Enrutadores" << endl;
        cout << "4. Eliminar Enrutador" << endl;
        cout << "5. Cambiar Costo Entre Nodos" << endl;
        cout << "6. Eliminar Conexion Entre Nodos" << endl;
        cout << "7. Consultar Costo de Envio" << endl;
        cout << "8. Consultar Camino a Seguir" << endl;
        cout << "9. Generar Red Aleatoria" << endl;
        cout << "10. Listar Enrutadores Activos" << endl;
        cout << "11. Limpiar Contenido de Pantalla " << endl;
        cout << "12. Salir" << endl;

        opcion = obtener_Entrada<int>("Ingrese una opcion:", 0, 11);

        switch (opcion) {
        case 1:
            cargar_Enrutadores(ruta);
            cout << "Se han cargado estos enrutadores del archivo ubicado en: " << ruta << endl;
            inicializar_Enrutamiento(ruta);
            listar_Enrutadores();
            break;

        case 2:
            enrutamiento_Aux.clear();
            gen_Enrutamiento();
            mostrar_EnrutamientoAuxiliar();
            actualizar_Enrutadores();
            break;

        case 3:
            cout << "Ingrese el nombre del enrutador:" << endl;
            cin >> aux;
            if(buscar_Instancia(aux) != -1){
                cout << "No se puede agregar algo que ya existe mijo" << endl;
                break;
            }
            else{
                enrutadores.push_back(aux);
                vector_Instancias.push_back(enrutador(aux));
                adyacentes_Aux[aux][aux] = 0;
                vector_Instancias.at(vector_Instancias.size()-1).setEnrutadoresVecinos(adyacentes_Aux);
                adyacentes_Aux.clear();
            }

            break;

        case 4:
            listar_Enrutadores();
            opcion = obtener_Entrada<int>("Ingrese el numero del enrutador:",0,vector_Instancias.size());
            aux = vector_Instancias.at(opcion-1).getNombre();
            eliminar_Instancia(aux);
            actualizar_Enrutadores();
            break;

        case 5:
            listar_Enrutadores();
            if(enrutadores.empty()){
                cout << "No hay enrutadores disponibles" << endl;
            }
            else{
            opcion = obtener_Entrada<int>("Ingrese el numero del enrutador:",0,vector_Instancias.size());
            enrutadorDestino = obtener_Entrada<int>("Ingrese el numero del enrutador destino:",0,vector_Instancias.size());
            costoAux = obtener_Entrada<int>("Ingrese el nuevo costo:",0,INT_MAX);
            vector_Instancias.at(opcion-1).agregar_Editar_Enlace(vector_Instancias.at(enrutadorDestino-1).getNombre(),costoAux);
            inicializar_Enrutamiento();
            }
            break;

        case 6:
            break;

        case 7:
            if(vector_Instancias.empty()){
                cout << "El vector esta vacio" << endl;
                break;
            }
            listar_Enrutadores();
            opcion = obtener_Entrada<int>("Ingrese el enrutador de origen:",0,vector_Instancias.size());
            enrutadorDestino = obtener_Entrada<int>("Ingrese el enrutador de destino:",0,vector_Instancias.size());
            aux = vector_Instancias.at(enrutadorDestino-1).getNombre();
            cout << "El coste de envio del enrutador " << vector_Instancias.at(opcion-1).getNombre() << " a " << vector_Instancias.at(enrutadorDestino-1).getNombre() << " es: ";
            vector_Instancias.at(opcion-1).mostrar_Coste(aux);
            break;

        case 8:
            break;

        case 9:
            opcion = obtener_Entrada<int>("Ingrese la cantidad de enrutadores:",0,INT_MAX);
            probabilidad = obtener_Entrada<float>("Ingrese la probalidad:",0,1);
            generar_GrafoAleatorio(opcion,probabilidad);
            inicializar_Enrutamiento();
            break;

        case 10:
            cout << "Los Enrutadores Activos Son:" << endl;
            listar_Enrutadores();
            break;

        case 11:
            system("cls");
            break;

        }
    } while (opcion != 12);
}


//Metodos getter y setter

vector<enrutador> red::getVector_Instancias() const
{
    return vector_Instancias;
}

void red::setVector_Instancias(const vector<enrutador> &newVector_Instancias)
{
    vector_Instancias = newVector_Instancias;
}

list<char> red::getEnrutadores() const
{
    return enrutadores;
}

void red::setEnrutadores(const list<char> &newEnrutadores)
{
    enrutadores = newEnrutadores;
}

map<unsigned char, map<unsigned char, int> > red::getEnrutadores_Vecinos() const
{
    return enrutadores_Vecinos;
}

void red::setEnrutadores_Vecinos(const map<unsigned char, map<unsigned char, int> > &newEnrutadores_Vecinos)
{
    enrutadores_Vecinos = newEnrutadores_Vecinos;
}

map<unsigned char, map<unsigned char, int> > red::getEnrutamiento_Aux() const
{
    return enrutamiento_Aux;
}

void red::setEnrutamiento_Aux(const map<unsigned char, map<unsigned char, int> > &newEnrutamiento_Aux)
{
    enrutamiento_Aux = newEnrutamiento_Aux;
}

map<unsigned char, int> red::getDistancias() const
{
    return distancias;
}

void red::setDistancias(const map<unsigned char, int> &newDistancias)
{
    distancias = newDistancias;
}

map<unsigned char, map<unsigned char, string> > red::getMapa_Caminos() const
{
    return mapa_Caminos;
}

void red::setMapa_Caminos(const map<unsigned char, map<unsigned char, string> > &newMapa_Caminos)
{
    mapa_Caminos = newMapa_Caminos;
}

