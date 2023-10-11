#include <enrutador.h>
#include <red.h>
#include <gestorTxt.h>

int main(){
    string ruta = "../Unidad4/Archivos/rutas.txt";
    red red_Principal;
    red_Principal.cargar_Enrutadores(ruta);
    red_Principal.inicializar_Enrutamiento(ruta);
    red_Principal.gen_Enrutamiento();
    red_Principal.mostrar_EnrutamientoAuxiliar();


}
