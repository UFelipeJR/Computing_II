#include <iostream>
#include "problemas.h"
using namespace std;


void problema1() {
    // Escriba un programa que identifique si un carácter ingresado es una vocal, una consonante
    // o ninguna de las 2 e imprima un mensaje según el caso.
    char A;
    cout << "Ingrese un caracter: "; cin >> A;

    if ((A >= 'a' && A <= 'z') || (A >= 'A' && A <= 'Z')) {
        if (A == 'a' || A == 'e' || A == 'i' || A == 'o' || A == 'u' || A == 'A' || A == 'E' || A == 'I' || A == 'O' || A == 'U') {
            cout << "Es una vocal" << endl;
        } else {
            cout << "Es una consonante" << endl;
        }
    } else {
        cout << "No es una letra" << endl;
    }
}

void problema3(){
    //Escriba un programa que debe leer un mes y un día de dicho mes para luego decir si esa combinación de mes
    //y día son válidos. El caso más especial es el 29 de febrero, en dicho caso imprimir posiblemente año bisiesto.
}

void problema5(){
    //Escriba un programa que muestre el siguiente patrón en la pantalla:
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *

}

void problema7(){
    //En la serie de Fibonacci, cada número es la suma de los 2 anteriores e inicia con 1 y
    //1. Ej: 1, 1, 2, 3, 5, 8, ....
    //Escriba un programa que reciba un número n y halle la suma de todos los números pares en la serie
    //de Fibonacci menores a n.

    int n, x=0,y=1,z=1, cont = 0;

    cout << "Ingrese el numero n: ";cin >> n;
    for(short int i = 1; i <n; i++){
        z = x+y;
        if(z%2 == 0 && z<n){
            cont += z;
        }
        x = y;
        y = z;
    }

    cout << "La suma de los elementos pares es: " << cont << endl;


}

void problema9(){
    //Escriba un programa que pida un número entero N e imprima el resultado de la suma
    //de todos sus dígitos elevados a sí mismos.


}

void problema11(){
    //Escriba un programa que reciba un número y calcule el mínimo común múltiplo de
    //todos los números enteros entre 1 y el número ingresado.

}

void problema13(){
    //Escriba un programa que reciba un número y calcule la suma de todos los primos
    //menores que el número ingresado.

}

void problema15(){
    //Empezando con el número 1 y moviéndose hacia la izquierda y en sentido horario
    //se genera una espiral de números como la siguiente:
    /*
    21 22 23 24 25
    20 7  8  9  10
    19 6  1  2  11
    18 5  4  3  12
    17 16 15 14 13
    */



}

void problema17(){
    //La secuencia de números triangulares se forma al sumar su posición en el arreglo
    //con el valor del número anterior: 1, 1+2=3, 3+3=6, 6+4=10, 10+5=15, 15+6=21, 21+7=28...
    //Si listamos los números triangulares y sus divisores tenemos:

}
