#include <funcionalidades.h>
#include <codificadores.h>

int main()
{
    int n = 4;
    string ruta = "../Unidad3/coded.dat";
    string  str = decodificador2(n,ruta);
    translateSemiCoded(str);
    //cout << str << endl;

    return 0;

}
