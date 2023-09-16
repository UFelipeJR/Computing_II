#include <funcionalidades.h>
#include <codificadores.h>

int main()
{

    string ruta = "../Unidad3/archivo.txt";
    string destino = "../Unidad3/coded.dat";
    string coded = "";
    int n =4;


    coded = metodo1(n,ruta);
    cout << coded << endl;

    write_file(destino, coded);


    return 0;

}
