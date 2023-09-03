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
     * arrayC: arreglo dinamico.
     *
     * Retorno:
     * array de caracteres.
    */

    char* arrayC = new char[size];
    cout << "Ingrese una cadena de caracteres:";
    //cin >> arrayC; // Por definir
    cin.getline(arrayC,size); // Por definir
    return arrayC;
}


char* genDinamicRandomAlphabet(const int size){

    /*
     * Generador de arreglo dinamico con n letras aleatorias
     *
     * Variables, constantes y arreglos.
     * size: tamaño máximo definido como constante para el arreglo.
     * arrayC: arreglo dinamico.
     * indiceRandom: numero aleatorio entre 0 y 26 que corresponde a la cantidad de letras del alfabeto.
     * letraRandom: letra alatoria generada con indiceRandom;
     *
     * Retorno:
     * array dinamico de n letras mayusculas.
    */

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


char upperChar(char caracter){

    /*
     * Conversor de caracter a mayúscula
     *
     * Variables, constantes y arreglos.
     * caracter: caracter que será convertido a mayuscula.
     *
     * Retorno:
     * caracter convertido en mayuscula.
    */

    if(caracter >= 'a' && caracter <= 'z'){
        return caracter - 32;
    }
    else{
        return caracter;
    }

}

bool checkRoman(char* array) {

    /*
     * Checker de posibles romanos
     *
     * Variables, constantes y arreglos.
     * punteroIterador: almacena dirección de memoria del primer elemento de CadenaC.
     * denominaciones: arreglo de caracteres que almacena las letras usadas para denominar los numeros romanos.
     *
     * Retorno:
     * true o false dependiendo de si es o no un posible romano
    */

    char* punteroIterador = array;
    char denominaciones[] = "MDCLXVI";

    while (*punteroIterador != '\0') {
        bool esValido = false;
        for (int i = 0; i < 7; i++) {
            if (*punteroIterador == denominaciones[i]) {
                esValido = true;
                break;
            }
        }
        if (!esValido) {
            return false;
        }
        punteroIterador++;
    }
    return true;
}

int equivRoman(char caracter){

    /*
     * Buscador de equivalencia de letra con numero romano
     *
     * Variables, constantes y arreglos.
     * romanos: arreglo de caracteres que almacena las letras usadas para denominar los numeros romanos.
     * valores: arreglo con los valores que pueden tomar los numeros romanos.
     *
     * Retorno:
     * true o false dependiendo de si es o no un posible romano
    */

    char romanos[] = "MDCLXVI";
    int valores[] = {1000,500,100,50,10,5,1};

    for(int i = 0; romanos[i] != '\0'; i++){
        if(caracter == romanos[i]){
            return valores[i];
        }
    }

    return -1;
}
