#include <funcionalidades.h>
#include <codecs.h>

int main(){

    string origen = "../Unidad3/Archivos/struct.txt";
    char* prueba = read_file(origen,1);


    int i = 0;
    const int filas = 5;
    const int columnas_maximas = 10; // Define un número máximo de columnas

    string** array = new string*[filas];

    while(prueba[i] != '\n'){
        cout << prueba[i];
        i ++;
    }



    return 0;
}



