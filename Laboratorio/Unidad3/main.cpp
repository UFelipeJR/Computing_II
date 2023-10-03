#include <funcionalidades.h>
#include <codecs.h>
#include <bank.h>








int main(){

    //menu_principal();

    string originU = "../Unidad3/Archivos/structU.txt";
    string destinoU = "../Unidad3/Archivos/structU.dat";


    remove("../Unidad3/Archivos/M1S15.txt");
    decodiWrite(destinoU,originU);



    return 0;
}



