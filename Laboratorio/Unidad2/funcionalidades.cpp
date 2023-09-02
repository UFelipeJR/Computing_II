#include <iostream>
#include "funcionalidades.h"
#include <cstdlib>
#include <ctime>

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


char* genDinamicRandomAlphabet(const int size){
    srand(time(NULL));
    char* arrayRandom = new char[size];
    char* punteroPrimario = arrayRandom;
    int indiceRandom;
    char letraRandom;

    for(int i = 0; i < size; i++){
        indiceRandom = rand() % 26;
        letraRandom = 'A' + indiceRandom;
        *punteroPrimario = letraRandom;
        punteroPrimario++;
    }

    return arrayRandom;
}


