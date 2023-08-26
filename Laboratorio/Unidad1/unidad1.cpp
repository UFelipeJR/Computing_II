#include <iostream>
#include <cstdlib>
#include <ctime>
#include "unidad1.h"
using namespace std;


//Ejercicios

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
    cout << "Ingrese el numero A: "; cin >> A;
    cout << "Ingrese el numero B: "; cin >> B;

    if(A > B){
        cout << A << endl;
    }

    else{
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

void ejercicio16(){
    //Escriba un programa que pida constantemente números hasta que se ingrese el número cero e imprima en pantalla
    //el promedio de los números ingresados (excluyendo el cero).
    int n = -1, cont = 0, cont_num = -1;

    while(n!=0){
        cout << "Ingrese un numero N y cero para finalizar:"; cin >>n;
        cont += n;
        cont_num ++;
    }
    cout << "El promedio de los numeros ingresados es: " << cont/cont_num << endl;
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

void ejercicio18(){

    int n = 0;
    cout << "Ingrese un numero N:"; cin >> n;
    bool raiz = false;

    for(int i = 0; i*i<=n;i++){
        if (i*i == n){
            raiz = true;
            }
    }

    if( raiz == true){
        cout << n << " es cuadrado perfecto." << endl;
    }
    else{
        cout << n << " no es cudraddo perfecto." << endl;
    }


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

void ejercicio20(){
    //Escriba un programa que pida un número N e imprima si es o no un palíndromo
    //(igual de derecha a izquierda que de izquierda a derecha).
    int n = 0,nAux = 0, invertido = 0;
    cout << "Ingrese un numero N:"; cin >> n;
    nAux = n;

    while (nAux > 0) {
        int digito = nAux % 10;
        invertido = invertido * 10 + digito;
        nAux /= 10;
    }

    if(n == invertido){
        cout << "El numero ingresado es palindromo" << endl;
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

void ejercicio22(){
    int n, h = 0, m = 0, s = 0;
    cout << "Ingrese el numero para calcular HH/MM/SS: "; cin >> n;

    h = (n/3600);
    m = (n%3600)/60;
    s = ((n%3600)%60);

    cout << h << ":" << m <<  ":" << s << endl;

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

void ejercicio24(){
    //Escriba un programa que pida una número entero e imprima un cuadrado de dicho
    //tamaño, los bordes del cuadrado deben estar hechos con el carácter `+' y el interior debe estar vacío.
    int n;
    cout << "Ingrese un numero N:"; cin >> n;

    for(int i = 0; i < n; i++){
        cout << "+";
    }
    cout << endl;

    for(int i = 0; i < n-2; i++){
        cout << "+";
        for(int j = 0; j < n-2; j++){
            cout << " ";
        }
        cout << "+";
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        cout << "+";
    }
    cout << endl;
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

void ejercicio26(){
    //Escriba un programa que pida tres números e imprima el tipo de triangulo (isósceles, equilátero, escaleno)
    //que se formaría, si sus lados tienen la longitud denida por los números ingresados. Tenga en cuenta el caso
    //en que los números ingresados no forman un triángulo.

    float a = 0,b = 0,c = 0;
    cout << "Ingrese el valor de a:"; cin >> a;
    cout << "Ingrese el valor de b:"; cin >> b;
    cout << "Ingrese el valor de c:"; cin >> c;

    if(a + b > c && a + c > b && b + c > a){
        cout << "Es posible crear un triangulo con estas medidas de lados \n";
    }

    else{
        cout << "Las longitudes ingresadas no forman un triangulo" << endl;
    }

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

void ejercicio28(){
    // Escriba un programa que encuentre el valor aproximado de pi en base a la siguiente
    //suma innita. El usuario debe ingresar el número de elementos usados en la aproximación.

}


void ejercicio29(){
    /*Escriba un programa que adivine un número A (entre 0 y 100) seleccionado por el usuario
    (el número NO se ingresa al programa), el programa imprimirá en pantalla un número B y el
    usuario usará los símbolos `>', `<' y `=' para indicarle al programa si B es mayor, menor o igual
    que A. El programa imprimira un nuevo número B, con base en simbolo ingresado por el usuario, y
    repetira el proceso hasta acertar el número seleccionado por usuario.*/

    int minimo = 0, maximo = 100, sel = (minimo+maximo)/2;
    char indicacion;
    while(sel != '='){
        cout << "Creo que el numero es: " << sel << endl;
        cout << "Ingrese <> o = para dar una indicacion:"; cin >> indicacion;
        if(indicacion == '='){
            cout << "El numero es: " << sel << endl;
            break;
        }
        else if(indicacion == '<'){
            sel-=1;
        }
        else if(indicacion == '>'){
            sel+=1;
        }
    }

}

void ejercicio30(){
    int n = rand()%100, user = 0;
    cout << n << endl;
    bool estado = false;

    while(estado != true){
        cout << "Ingrese un numero: "; cin >> user;
        estado = true;
    }


}


//Problemas

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
    int mes,dia;
    cout << "Ingrese el mes:"; cin >> mes;
    cout << "Ingrese el dia:"; cin >> dia;

    if(mes > 12 || dia > 30 ){
        cout << dia << "/" << mes <<  " no es valida " << endl;
    }


    else if(dia == 29 && mes ==2){
        cout << dia << "/" << mes <<  " es una fecha invalida para bisiesto" << endl;
    }

    else{
        cout << dia << "/" << mes <<  " es una fecha valida " << endl;
    }


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


void problema15() {
    // Empezando con el número 1 y moviéndose hacia la izquierda y en sentido horario
    // se genera una espiral de números como la siguiente:
    /*
    21 22 23 24 25
    20 7  8  9  10
    19 6  1  2  11
    18 5  4  3  12
    17 16 15 14 13
    */

    int n;
    cout << "Ingrese un numero impar N: ";cin >> n;

    int sumaDiagonal = 1;
    int maximo = 1;
    int incremento = 2;

    for (int i = 1; i <= n / 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            maximo += incremento;
            sumaDiagonal += maximo;
        }
        incremento += 2;
    }

    cout << "La suma de la diagonal es: " << sumaDiagonal << endl;

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


// Menu
void menu_principal(){
    int n = 0, modo = 0, EjerProblem = 1;
    cout << "*************************************************************************\n";
    cout << "*                          Menu Principal                               *\n";
    cout << "*************************************************************************\n";


    cout << "Seleccione:\n1. Ejercicios \n2. Problemas \n";
    cin >> n;

    if(n == 1){
        cout << "Ingrese el numero correspondiente al ejercicio que desea visualizar:" << endl; cin >> EjerProblem;
        switch(EjerProblem){
            case 1:
                ejercicio1();
                break;

            default:
                cout << "No ha seleccionado una opcion valida.";
        }

    }

    else if(n == 2){
        cout << "Ingrese el numero correspondiente al problema que desea visualizar:" << endl; cin >> EjerProblem;
        switch(EjerProblem){
            case 1:
                problema1();
                break;

            default:
                cout << "No ha seleccionado una opcion valida.";
        }
    }
}



