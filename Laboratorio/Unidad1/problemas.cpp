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
    //Este ejericicio se debe optimizar
    //Escriba un programa que muestre el siguiente patrón en la pantalla:
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *

    short int n;
    cout << "Ingrese un numero impar: ";cin >> n;
    short int esp_blancos = (n-1)/2, ast = 1;


    for(short i = 0; i < (n+1)/2; i++){

        for(short int j = 0; j < esp_blancos; j++){
            cout << " ";
        }

        for(short int k = 0; k < ast; k++){
            cout << "*";
        }

        for(short int m = 0; m < esp_blancos; m++){
            cout << " ";
        }
        esp_blancos -= 1;
        ast += 2;
        cout << endl;
    }

    esp_blancos += 2;
    ast -= 4;

    for(short i = (n-1)/2; i > 0; i--){
        for(short int j = 0; j < esp_blancos; j++){
            cout << " ";
        }

        for(short int k = 0; k < ast; k++){
            cout << "*";
        }

        for(short int m = 0; m < esp_blancos; m++){
            cout << " ";
        }
        esp_blancos += 1;
        ast -= 2;
        cout << endl;

    }
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
    int n,digito,cont;
    cout << "Ingrese el numero N:"; cin>>n;

    while(n>0){
        digito = n%10;
        n /= 10;
        int potencia = 1;
        for(int i = 1; i<=digito;i++){
            potencia = potencia*digito;
        }
        cont += potencia;
    }
    cout << "La suma de los digitos elevados por si mismos es: " << cont << endl;


}


// Problema 11

int mcm(int A, int B) {

    // Se calcula el MCM de dos numeros
    int i = 1;
    bool estado = false;

    while (!estado) {
        if (i % A == 0 && i % B == 0) {
            estado = true;
        }
        i += 1;
    }
    return i - 1;
}

void problema11(){
    //Escriba un programa que reciba un número y calcule el mínimo común múltiplo de
    //todos los números enteros entre 1 y el número ingresado.


    short int n, resultado = 1;
    cout << "Ingrese un numero N:"; cin >> n;

    for(int i=1;i<=n;i++){
        resultado = mcm(resultado,i);
    }

    cout << "El minimo comun multiplo es: " << resultado << endl;

}


void problema13(){
    //Escriba un programa que reciba un número y calcule la suma de todos los primos
    //menores que el número ingresado.
    int n, contT = 0;
    cout << "Ingrese un numero N: ";
    cin >> n;

    for (int i = 2; i < n; i++) {
        int contDiv = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                contDiv++;
            }
        }
        if (contDiv == 2) {
            contT += i;
        }
    }

    cout << "El resultado de la suma es: " << contT << endl;

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
    int k;
    cout << "Ingrese el minimo de divisores:"; cin >>k;
    bool state = false;

    int i=1;
    while(state != true){
        int aux = i*(i+1)/2,contDiv = 0;
        for(int j = 1; j<= aux; j++){
            if(aux%j == 0){
                contDiv += 1;
            }
        }

        if(contDiv > k){
            state = true;
            cout << "El numero es "<<aux << " que tiene " << contDiv << " divisores" << endl;
        }

        i += 1;

    }

}
