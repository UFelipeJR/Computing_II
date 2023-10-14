#include <enrutador.h>
#include <red.h>
#include <gestorTxt.h>

int main(){
    srand(time(NULL));

    //string ruta = "../Unidad4/Archivos/rutas.txt";
    red red_Principal;
    //red_Principal.cargar_Enrutadores(ruta);
    red_Principal.generar_GrafoAleatorio(20,0.5);
    red_Principal.inicializar_Enrutamiento();
    red_Principal.gen_Enrutamiento();
    red_Principal.actualizar_Enrutadores();
    red_Principal.mostrar_EnrutamientoAuxiliar();

    //int n = 6;
    //int k = 8;
    //red_Principal.generar_GrafoAleatorio(3,0.4);
    //Cambiar auto

    /*
    map<unsigned char, map<unsigned char, int>> enrutamiento_Aux;
    enrutamiento_Aux['A']['B'] = 2;
    enrutamiento_Aux['A']['C'] = 2;
    enrutamiento_Aux['A']['D'] = 2;

    enrutador A('A');
    A.setTablaEnrutamiento(enrutamiento_Aux);
    A.mostrar_Enrutamiento();
    */


}
