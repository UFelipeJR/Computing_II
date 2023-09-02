#include <iostream>
#include "problemas.h"
#include "funcionalidades.h"
using namespace std;


void contAlphabet_Problema2(){

}


void stringToInt_Problema4(){

    /*
     * Problema 4
     * Haga una función que reciba una cadena de caracteres numéricos, la convierta a un número entero
     * y retorne dicho número. Escriba un programa de prueba.
     * Ejemplo: si recibe la cadena “123”, debe retornar un int con valor 123.
     *
     * Variables, constantes y arreglos:
     * resultado: calculo inicial equivalente a las cadenas de caracteres.
     * cadenaD: definicion de arreglo con el uso de una funcion.
     * punteroPrimario: almacena la dimensión de memoria del primer elemento del arreglo dinamico.
     * signo: valor que determina si el valor entero será positivo o negativo.
    */

    int resultado = 0;
    char* cadenaD = genDinamicCharArray(50);
    char* punteroPrimario = cadenaD;
    int signo = 1;

    if(*punteroPrimario == '-'){
        signo = -1;
    }
    while(*punteroPrimario != '\0'){
        if(*punteroPrimario >= '0' && *punteroPrimario <= '9'){
            resultado = resultado * 10 + (*punteroPrimario - '0');
        }
        punteroPrimario ++;
    }

    cout << "El numero entero es: " << resultado * signo << endl;

    delete[] cadenaD;
}


void splitCharNum_Problema8(){

    /*
     * Problema 8
     * Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres,
     * generando una cadena que no tiene números y otra con los números que había en la cadena original.
     * Si se recibe abc54rst el programa debe imprimir las cadenas: abcrst y 54.
     *
     * Variables, constantes y arreglos:
     * cadenaC: definicion de arreglo con el uso de una funcion.
     * punteroPrimario: almacena dirección de memoria del primer elemento de CadenaC.
     * punteroSecundario: almacena dirección de memoria del primer elemento de CadenaC.
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
