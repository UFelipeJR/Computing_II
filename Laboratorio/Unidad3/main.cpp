#include <funcionalidades.h>
#include <codecs.h>

int main(){

    string origen = "../Unidad3/prueba.txt";
    string destino = "../Unidad3/prueba.dat";

    /*
    string a  = metodo1(80, origen);
    char* conver = stringBinaryToArray(a);
    cout << conver << endl;
    write_file(destino,conver,2);
    */

    string b = decodificador1(80,destino);
    cout << b << endl;





    return 0;
}



