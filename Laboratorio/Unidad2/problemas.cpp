#include <iostream>
#include "problemas.h"
using namespace std;




void splitCharNum_Problema8() {

    /*
     * Problema 8
     * Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres,
     * generando una cadena que no tiene números y otra con los números que había en la cadena original.
     *
     * Variables, constantes y arreglos.
     * size: tamaño máximo definido como constante para el arreglo.
     * cadenaC: definicion de arreglo con tamaño constante.
     * punteroPrimario: almacena dirección de memoria del primer elemento de CadenaC
     * punteroSecundario: almacena dirección de memoria del primer elemento de CadenaC
    */

    const int size = 50;
    char cadenaC[size];
    char *punteroPrimario;
    char *punteroSecundario;
    cout << "Ingrese la cadena de caracteres:";
    cin >> cadenaC;
    //cin.getline(cadenaC,size) Por definir
    punteroPrimario = cadenaC;
    punteroSecundario = cadenaC;


    //Se itera en todo el arreglo con el rango de las letras mayúsculas y minúsculas en ASCII
    while (*punteroPrimario != '\0') {
        if((*punteroPrimario >= 'a' && *punteroPrimario <= 'z') || (*punteroPrimario >= 'A' && *punteroPrimario <= 'Z') ){
            cout << *punteroPrimario;
        }
        punteroPrimario++;
    }

    cout << " y ";

    //Se itera en todo el arreglo con el rango de los números en ASCII
    while (*punteroSecundario != '\0') {
        if(*punteroSecundario >= '0' && *punteroSecundario <= '9'){
            cout << *punteroSecundario;
        }
        punteroSecundario++;
    }

    cout << endl;

}
