/*
#include <enrutador.h>
#include <red.h>
#include <gestorTxt.h>


int main(){
    srand(time(NULL));
    string ruta = "../Unidad4/Archivos/rutas.txt";
    red red_Principal;
    red_Principal.cargar_Enrutadores(ruta);
    //red_Principal.listar_Enrutadores();
    red_Principal.inicializar_Enrutamiento(ruta);
    red_Principal.gen_Enrutamiento();
    red_Principal.actualizar_Enrutadores();
    map<unsigned char, map<unsigned char, string >> mapa_Caminos = red_Principal.getMapa_Caminos();
    cout << mapa_Caminos['A']['E'] << endl;
    red_Principal.mostrar_EnrutamientoAuxiliar();
    //char a = 'E';
    //red_Principal.eliminar_Instancia(a);
    //red_Principal.inicializar_Enrutamiento();
    //red_Principal.gen_Enrutamiento();
    //red_Principal.actualizar_Enrutadores();
    //red_Principal.pruebas();
    //red_Principal.mostrar_EnrutamientoAuxiliar();



}
*/


