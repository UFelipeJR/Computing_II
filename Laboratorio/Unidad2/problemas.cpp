#include <iostream>
#include "problemas.h"
#include "funcionalidades.h"
using namespace std;


void stringToInt_Problema4(){
    char* CadenaD = genDinamicCharArray(50);


}






void splitCharNum_Problema8(){

    /*
     * Problema 8
     * Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres,
     * generando una cadena que no tiene números y otra con los números que había en la cadena original.
     *
     * Variables, constantes y arreglos.
     * cadenaC: definicion de arreglo con el uso de una funcion.
     * punteroPrimario: almacena dirección de memoria del primer elemento de CadenaC
     * punteroSecundario: almacena dirección de memoria del primer elemento de CadenaC
    */

    char* cadenaC = genDinamicCharArray(50);
    char* punteroPrimario = cadenaC;
    char* punteroSecundario = cadenaC;

    //Se itera en todo el arreglo con el rango de las letras mayúsculas y minúsculas en ASCII
    while(*punteroPrimario != '\0'){
        if((*punteroPrimario >= 'a' && *punteroPrimario <= 'z') || (*punteroPrimario >= 'A' && *punteroPrimario <= 'Z') ){
            cout << *punteroPrimario;
        }
        punteroPrimario++;
    }

    cout << " y ";

    //Se itera en todo el arreglo con el rango de los números en ASCII
    while(*punteroSecundario != '\0'){
        if(*punteroSecundario >= '0' && *punteroSecundario <= '9'){
            cout << *punteroSecundario;
        }
        punteroSecundario++;
    }

    cout << endl;

    delete[] cadenaC;
}
