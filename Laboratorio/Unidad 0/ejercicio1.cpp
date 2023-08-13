// Uso básico de puntero para obtener dirección de memoria de una variable y cambiar su valor

#include <iostream>
using namespace std;

int main(){
    int x = 0, *xp = &x;

    cout << "La direccion de memoria es: " << xp << "y el numero es: " << x << endl; 

    cout << "Ingrese el nuevo valor de la variable: "; cin >> *xp ;

    cout << "La direccion de memoria sigue siendo: " << xp << "y el numero es: " << x << endl;



}