// Escribe un algoritmo cuya entrada sea un número entero y muestra el resultado de la suma de todos sus dígitos elevados a sí mismos.
// Ejemplo: si el número ingresado es 231 el resultado será 2^2+3^3+1^1=32, el programa mostrará el número 32.

#include <iostream>
#include <locale.h>
#include <math.h>
#include <string>
using namespace std;

int main(){
    setlocale(LC_ALL, ""); 

    wstring numero; int cont = 0;
    wcout << L"Ingrese un número: "; 
    wcin >> numero;

    for(int i = 0; i < numero.length();i++){
        int valorEntero = static_cast<int>(numero[i]) - L'0';
        cont += pow(valorEntero,valorEntero);
    }

    wcout << cont;
    
    return 0;
}
