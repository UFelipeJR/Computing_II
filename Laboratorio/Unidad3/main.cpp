#include <funcionalidades.h>
#include <codecs.h>



int main(){

    string origen = "../Unidad3/Archivos/prueba.txt";
    string destino = "../Unidad3/Archivos/prueba.dat";
    int seed = 6;


    cout << "Al codificar: " << endl;
    string a = metodo1(seed,origen);
    cout << translateSemiCoded(a) << endl;
    write_file(destino,a,2);
    string b = decodificador1(seed,destino);
    cout << "Al decodificar:" << endl;
    cout << translateSemiCoded(b) << endl;


    /*
    cout << "Al codificar: " << endl;
    string a = metodo2(seed,origen);
    cout << translateSemiCoded(a) << endl;
    write_file(destino,a,2);
    string b = decodificador2(seed,destino);
    cout << "Al decodificar:" << endl;
    cout << translateSemiCoded(b) << endl;
    */


    return 0;
}



