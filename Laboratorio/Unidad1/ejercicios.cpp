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


