#include <enrutador.h>
#include <red.h>
#include <gestorTxt.h>


int main(){
    red red_Principal;
    string ruta = "../Unidad4/Archivos/rutas.txt";
    srand(time(NULL));
    red_Principal.menu(ruta);

    /*
    string ruta = "../Unidad4/Archivos/rutas.txt";

    red_Principal.inicializar_Enrutamiento(ruta);
    red_Principal.gen_Enrutamiento();
    red_Principal.actualizar_Enrutadores();
    //map<unsigned char, map<unsigned char, string >> mapa_Caminos = red_Principal.getMapa_Caminos();
    //cout << mapa_Caminos['A']['E'] << endl;
    red_Principal.mostrar_EnrutamientoAuxiliar();
    //char a = 'E';
    //red_Principal.eliminar_Instancia(a);
    //red_Principal.inicializar_Enrutamiento();
    //red_Principal.gen_Enrutamiento();
    //red_Principal.actualizar_Enrutadores();
    //red_Principal.pruebas();
    //red_Principal.mostrar_EnrutamientoAuxiliar();
    */
    //red_Principal.obtener_Entrada("Ingrese una opcion:",1,100);

}



