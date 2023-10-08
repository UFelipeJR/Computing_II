#include <enrutador.h>
#include <red.h>
#include <gestorTxt.h>



int main() {

    string ruta = "../Unidad4/Archivos/rutas.txt";
    enrutador router1('Z');
    router1.extraer_Enrutamiento(ruta);

    return 0;
}
