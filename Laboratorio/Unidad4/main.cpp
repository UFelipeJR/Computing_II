#include <enrutador.h>
#include <red.h>
#include <gestorTxt.h>



int main() {

    string ruta = "../Unidad4/Archivos/rutas.txt";
    //red red_Principal;
    //red_Principal.lista_Enrutadores(ruta);
    //red_Principal.listar_Enrutadores();
    enrutador router1('A');
    router1.cargar_Vecinos(ruta);
    router1.getEnrutadoresVecinos();



    return 0;
}
