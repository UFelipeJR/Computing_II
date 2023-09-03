#include <iostream>
#include "problemas.h"
#include "funcionalidades.h"
using namespace std;


void contAlphabet_Problema2(){

    /*
     * Problema 2
     * Elabore un programa que genere un arreglo de 200 letras mayúsculas aleatorias, imprima este arreglo
     * y luego imprima cuantas veces se repite cada letra en el arreglo.
     * Ejemplo: supóngase que se genera el arreglo de 10 elementos: ABARSECAAB. El programa debe imprimir: ABAR-SECAAB
     *
     * Variables, constantes y arreglos:
     * arregloLetras: definición de arreglo con uso de una función.
     * punteroIterador: almacena la dirección de memoria del primer elemento del arreglo dinamico.
     * contAparicion: contador de apariciones de una letra.
     *
     * Retorno:
     * Vacio
    */

    char* arregloLetras = genDinamicRandomAlphabet(200);
    char* punteroIterador = arregloLetras;
    int contAparicion = 0;

    for (char letra = 'A'; letra <= 'Z'; letra++) {
        while(*punteroIterador != '\0'){
            if(letra == *punteroIterador){
                contAparicion ++;
            }
            punteroIterador ++;
        }
        cout << letra << ":" << contAparicion << endl;
        contAparicion = 0;
        punteroIterador = arregloLetras;
    }
    delete[] arregloLetras;

}


void charsToInt_Problema4(){

    /*
     * Problema 4
     * Haga una función que reciba una cadena de caracteres numéricos, la convierta a un número entero
     * y retorne dicho número. Escriba un programa de prueba.
     * Ejemplo: si recibe la cadena “123”, debe retornar un int con valor 123.
     *
     * Variables, constantes y arreglos:
     * resultado: calculo inicial equivalente a las cadenas de caracteres.
     * cadenaD: definicion de arreglo con el uso de una funcion.
     * punteroIterador: almacena la dirección de memoria del primer elemento del arreglo dinamico.
     * signo: valor que determina si el valor entero será positivo o negativo.
     *
     * Retorno:
     * vacio
    */

    int resultado = 0;
    char* cadenaD = genDinamicCharArray(50);
    char* punteroIterador = cadenaD;
    int signo = 1;

    if(*punteroIterador == '-'){
        signo = -1;
    }
    while(*punteroIterador != '\0'){
        if(*punteroIterador >= '0' && *punteroIterador <= '9'){
            resultado = resultado * 10 + (*punteroIterador - '0');
        }
        punteroIterador ++;
    }

    cout << "El numero entero es: " << resultado * signo << endl;

    delete[] cadenaD;
}

void upperWord_Problema6(){

    /*
     * Problema 6
     * Escriba un programa que reciba una cadena de caracteres y cambie las letras minúsculas por
     * mayúsculas, los demás caracteres no deben ser alterados.
     * Ejemplo: se recibe Man-zana debe mostrar MAN-ZANA.
     *
     * Variables, constantes y arreglos:
     * cadenaC: definicion de arreglo con el uso de una funcion.
     * punteroIterador: almacena dirección de memoria del primer elemento de CadenaC.
     *
     * Retorno:
     * vacio
    */

    char* cadenaC = genDinamicCharArray(50);
    char* punteroIterador = cadenaC;

    cout << "Original: ";

    while(*punteroIterador != '\0'){
        cout << *punteroIterador;
        punteroIterador ++;
    }

    cout << ". En mayuscula: ";
    punteroIterador = cadenaC;
    while(*punteroIterador != '\0'){
        cout << upperChar(*punteroIterador);
        punteroIterador ++;
    }

    cout << endl;
    delete[] cadenaC;

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
     * punteroIterador: almacena dirección de memoria del primer elemento de CadenaC.
     *
     * Retorno:
     * vacio
    */

    char* cadenaC = genDinamicCharArray(50);
    char* punteroIterador = cadenaC;

    //Se itera en todo el arreglo con el rango de las letras mayúsculas y minúsculas en ASCII
    while(*punteroIterador != '\0'){
        if((*punteroIterador >= 'a' && *punteroIterador <= 'z') || (*punteroIterador >= 'A' && *punteroIterador <= 'Z') ){
            cout << *punteroIterador;
        }
        punteroIterador++;
    }

    punteroIterador = cadenaC;
    cout << " y ";

    //Se itera en todo el arreglo con el rango de los números en ASCII
    while(*punteroIterador != '\0'){
        if(*punteroIterador >= '0' && *punteroIterador <= '9'){
            cout << *punteroIterador;
        }
        punteroIterador++;
    }

    cout << endl;

    delete[] cadenaC;
}


void romanToArabic_problema10() {

    /*
     * Problema 10
     * Escribir un programa que permita convertir un número en el sistema romano al sistema arábigo
     * usado actualmente. A continuación se encuentran los caracteres usados en el sistema romano y su
     * equivalente arábigo:
     * M: 1000
     * D: 500
     * C: 100
     * L: 50
     * X: 10
     * V: 5
     * I: 1
     *
     * Variables, constantes y arreglos:
     * romanNumber: definicion de arreglo con el uso de una funcion.
     * punteroIterador: almacena dirección de memoria del primer elemento de romanNumber.
     * romanoActual: numero romano equivalente relacionado a una posicion y una letra.
     * romanoSiguiente: numero siguiente a romano actual.
     * total: contador total de numero arabico.
     *
     * Retorno:
     * vacio
    */

    char* romanNumber = genDinamicCharArray(50);
    char* punteroIterador = romanNumber;
    int romanoActual = 0;
    int romanoSiguiente = 0;
    int total = 0;

    cout << "El numero ingresado fue: ";

    if (!checkRoman(romanNumber)) {
        cout << "El numero romano ingresado no es valido" << endl;
    }

    else {
        while (*punteroIterador != '\0') {
            cout << *punteroIterador;
            romanoActual = equivRoman(*punteroIterador);

            // Verificamos si existe un numero después del actual
            if (*(punteroIterador + 1) != '\0') {
                romanoSiguiente = equivRoman(*(punteroIterador + 1));

                if(romanoActual < romanoSiguiente){
                    total -= romanoActual;
                }

                else{
                    total += romanoActual;
                }

            }

            else {
                total += romanoActual;
            }

            punteroIterador++;
        }
    }

    cout << endl << "Corresponde a: " << total << endl;
    delete[] romanNumber;
}

