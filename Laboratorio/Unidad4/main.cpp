#include <enrutador.h>
#include <red.h>
#include <gestorTxt.h>



int main() {

    string ruta = "../Unidad4/Archivos/rutas.txt";
    enrutador router1('A');
    router1.extraer_Enrutamiento(ruta);
    //router1.getTablaEnrutamiento();
    router1.mostrar_Costo('A','z');

    /*
    enrutador instanciaAuxiliar;
    char letra = 65;
    int n = 5;
    vector<enrutador> vector_Instancias;

    for(int i = 0; i<n; i++){
        enrutador instancia(letra);
        vector_Instancias.push_back(instancia);
        letra ++;
    }

    for (int i = 0; i < vector_Instancias.size(); i++) {
        instanciaAuxiliar = vector_Instancias[i];
        instanciaAuxiliar.extraer_Enrutamiento(ruta);
        instanciaAuxiliar.getTablaEnrutamiento();
    }
    */



    return 0;
}
