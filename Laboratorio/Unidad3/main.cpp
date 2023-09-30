#include <funcionalidades.h>
#include <codecs.h>

int main(){


    //string origen = "../Unidad3/M1S15.txt";
    //string a  = metodo1(15, origen);


    string origen = "../Unidad3/prueba.txt";
    string destino = "../Unidad3/codi.dat";

    /*
    string pru = metodo1(64,origen);
    cout << pru << endl;
    char* conver = stringBinaryToArray(pru);

    write_file(destino,conver,2);

    string pru2 = decodificador1(4,destino);
    cout << pru2 << endl;
    //cout << stringBinaryToArray(pru2) << endl;
    */

    read_file(origen,1);
}



