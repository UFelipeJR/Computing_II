#include <enrutadores.h>
#include <red.h>
#include <gestorTxt.h>

ostream& operator<<(ostream& os, const vector<unsigned char>& vec)
{
    for (int i = 0; i < vec.size(); ++i) {
        os << vec[i];
    }
    return os;
}



int main()
{
    string ruta = "../Unidad4/Archivos/rutas.txt";
    gestorTxt objeto;

    vector<unsigned char> resultado = objeto.leerArchivo(ruta);
    cout << resultado << endl;
    return 0;
}
