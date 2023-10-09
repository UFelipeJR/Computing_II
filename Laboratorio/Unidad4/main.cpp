#include <enrutador.h>
#include <red.h>
#include <gestorTxt.h>



int main() {

    string ruta = "../Unidad4/Archivos/rutas.txt";
    red red_Principal;
    red_Principal.lista_Enrutadores(ruta);
    red_Principal.listar_Enrutadores();




    return 0;
}
