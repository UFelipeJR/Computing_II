#include <funcionalidades.h>
#include <codificadores.h>

int main()
{
    //int n = 4;
    //string ruta = "../Unidad3/coded.dat";
    //decodificador1(n,ruta);

    //string texto = "01000001 01100010 01000011 01100100";
    string texto = "01000001011000100100001101100100";
    cout << binaryToArray(texto) << endl;


    return 0;

}
