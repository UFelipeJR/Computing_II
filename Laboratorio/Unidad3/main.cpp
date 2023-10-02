#include <funcionalidades.h>
#include <codecs.h>
#include <bank.h>

int main(){
    string ruta = "../Unidad3/Archivos/structU.txt";
    string** h = addCol(ruta);

    for(int i = 0; i< 5; i++){
        for(int j = 0; j < 6; j++){
            cout << h[i][j] << " ";
        }
        cout << endl;
    }





    return 0;
}



