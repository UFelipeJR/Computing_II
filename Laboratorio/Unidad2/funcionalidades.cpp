#include <iostream>
#include "funcionalidades.h"
using namespace std;

char* genDinamicCharArray(const int size){

    /*
     * Generador de arreglo dinamico char
     *
     * Variables, constantes y arreglos.
     * size: tamaño máximo definido como constante para el arreglo.
     * arrayC: arreglo dinamico
    */

    char* arrayC = new char[size];
    cout << "Ingrese una cadena de caracteres:";
    //cin >> arrayC; // Por definir
    cin.getline(arrayC,size); // Por definir
    return arrayC;
}
