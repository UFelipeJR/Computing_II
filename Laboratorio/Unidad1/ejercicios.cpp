#include <iostream>
#include "ejercicios.h"
using namespace std;

void ejercicio1(){
    // Escriba un programa que pida dos números A y B e imprima en pantalla el residuo de la división A/B.
    short A,B;
    cout << "Ingrese el numero B: "; cin >> B;
    cout << "Ingrese el numero A: "; cin >> A;
    cout << A%B << endl;
}

void ejercicio3(){
    // Escriba un programa que pida dos números A y B e imprima en pantalla el mayor.
    short A,B;
    cout << "Ingrese el numero B: "; cin >> B;
    cout << "Ingrese el numero A: "; cin >> A;

    if(A > B){
        cout << A << endl;
    }

    else if(B > A){
        cout << B << endl;
    }
}

void ejercicio5(){
    // Escriba un programa que pida dos números A y B e imprima en pantalla la división
    float A,B;
    cout << "Ingrese el numero A: "; cin >> A;
    cout << "Ingrese el numero B: "; cin >> B;

    if(B==0){
        cout << "El denominador no puede ser cero";
    }

    else{

        if((A/B)-int(A/B) >= 0.5){
            cout << "El numero redondeado es: " << int((A/B)+1) << endl;
        }
        else{

            cout << "El numero redondeado es:" << int((A/B)) << endl;
        }
    }
}


void ejercicio7(){
    // Escriba un programa que pida un número N e imprima en pantalla la suma de todos los números entre 0 y N (incluyéndose el mismo).
    short n, count = 0;
    cout << "Ingrese un numero:"; cin >> n;

    for(int i = 1; i <= n; i++){
        count += i;
    }

    cout << count << endl;
}

void ejercicio9(){
    // Escriba un programa que pida un número N e imprima el perímetro y área de un círculo con radio N.
    short n;
    cout << "Ingrese el numero N: "; cin >> n;
    cout << "El perimetro es: " << 2*3.1416*n << endl;
    cout << "El area es: " << 3.1416*(n*n) << endl;
}

void ejercicio11(){
    // Escriba un programa que pida un número N e imprima en pantalla su tabla de multiplicar hasta 10xN.
    short n;
    cout << "Ingrese el numero N para calcular la tabla de multiplicar: "; cin >> n;

    for(short int i = 1; i <= 10; i++){
        cout << n << "x" << i << "=" << n*i << endl;
    }
}

void ejercicio13(){
    // Escriba un programa que pida un número N e imprima todos los divisores de N.
    short n;
    cout << "Ingrese el numero N para calcular los divisores: "; cin >> n;

    for (short int i = 1; i <= n; i++) {
        if(n%i == 0){
            cout << i << endl;
        }
    }
}

void ejercicio15(){
    //Escriba un programa que pida constantemente números hasta que se ingrese el número cero e imprima en
    //pantalla la suma de todos los números ingresados.
    short int n = -1, cont = 0;
    while(n != 0){
        cout << "Ingrese un numero para agregar al contador y 0 para finalizar: "; cin >> n;
        cont += n;
    }

    cout << "La sumatoria de todos los numeros es de: " << cont << endl;

    }

void ejercicio17() {
    //Escriba un programa que pida constantemente números hasta que se ingrese el número cero e imprima en
    //pantalla el mayor de todos los números ingresados.

    short int n = 0, mayor = 0;

    do {
        cout << "Ingrese un numero para encontrar el mayor y 0 para finalizar: ";
        cin >> n;
        if (n > mayor) {
            mayor = n;
        }
    } while (n != 0);

    cout << "El numero mayor es: " << mayor << endl;
}



