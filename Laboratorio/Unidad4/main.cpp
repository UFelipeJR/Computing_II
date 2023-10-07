#include <enrutadores.h>
#include <red.h>
#include <gestorTxt.h>

int main()
{
    string ruta = "../Unidad4/Archivos/rutas.txt";
    gestorTxt objeto;

    vector<unsigned char> resultado = objeto.leerArchivo(ruta);
    cout << resultado << endl;
    return 0;
}
