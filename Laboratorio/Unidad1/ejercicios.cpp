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
    short int n, count = 0;
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

    short int n, mayor = 0;

    do {
        cout << "Ingrese un numero para encontrar el mayor y 0 para finalizar: ";
        cin >> n;
        if (n > mayor) {
            mayor = n;
        }
    } while (n != 0);

    cout << "El numero mayor es: " << mayor << endl;
}

void ejercicio19(){
    //Escriba un programa que pida un número N e imprima si es o no un número primo.

    short int n, cont = 0;
    cout << "Ingrese un numero:"; cin >> n;

    for(short int i = 1; i <= n; i++){
        if(n%i == 0){
            cont += 1;
        }

    }

    if(cont == 2){
        cout << "Es primo" << endl;
    }
    else{
        cout << "No es primo" << endl;
    }
}

void ejercicio21(){
    //Escriba un programa que pida un carácter C, si es una letra la debe convertir de mayúscula
    //a minúscula y viceversa e imprimirla.

    char letra;
    cout << "Ingrese una letra: "; cin >> letra;

    if(letra >= 'a' && letra <= 'z'){
        cout << "La letra es: " << char(letra-32) << endl;
    }

    if(letra >= 'A' && letra <= 'Z'){
        cout << "La letra es: " << char(letra+32) << endl;
    }
}

void ejercicio23(){
    //Escriba un programa que pida dos números A y B e imprima en pantalla el mínimo común múltiplo
    //entre los dos.

    short int A,B,i=1;
    bool estado = false;
    cout << "Ingrese el numero A:"; cin >> A;
    cout << "Ingrese el numero B:"; cin >> B;

    while(estado != true){
        if(i%A == 0 && i%B == 0 ){
            estado = true;
        }
        i += 1;
    }
    cout << "El MCM de los dos numeros es: " << i-1 << endl;
}


void ejercicio25(){
    //Escriba un programa que pida un número N e imprima en pantalla la cantidad de
    //dígitos de N.
    int n, cont = 0;
    cout << "Ingrese el numero N:"; cin >> n;

    while(n > 0){
        n /= 10;
        cont ++;
    }

    cout << "La cantidad de digitos es: " << cont << endl;


}

void ejercicio27() {
    // Escriba un programa que actúe como una calculadora con operaciones de suma, resta, multiplicación y división,
    // el usuario debe ingresar los operandos y la operación a realizar.
    int A, B;
    char operando;

    cout << "Ingrese el numero A: "; cin >> A;
    cout << "Ingrese el numero B: "; cin >> B;
    cout << "Ingrese el operando: "; cin >> operando;

    if (operando == '+') {
        cout << A << "+" << B << "=" << A + B << endl;
    }
    else if (operando == '-') {
        cout << A << "-" << B << "=" << A - B << endl;
    }
    else if (operando == 'x' || operando == 'X') {
        cout << A << "x" << B << "=" << A * B << endl;
    }
    else if (operando == '/') {
        if (B != 0) {
            cout << A << "/" << B << "=" << A / B << endl;
        } else {
            cout << "No se puede dividir entre cero" << endl;
        }
    }
    else {
        cout << "El operador no es valido" << endl;
    }
}

void ejercicio29(){
    /*Escriba un programa que adivine un número A (entre 0 y 100) seleccionado por el usuario
    (el número NO se ingresa al programa), el programa imprimirá en pantalla un número B y el
    usuario usará los símbolos `>', `<' y `=' para indicarle al programa si B es mayor, menor o igual
    que A. El programa imprimira un nuevo número B, con base en simbolo ingresado por el usuario, y
    repetira el proceso hasta acertar el número seleccionado por usuario.*/

    int numero;
    cout << "Ingrese el numero que el sistema adivinara"; cin >> numero;
    cout << numero;

}


