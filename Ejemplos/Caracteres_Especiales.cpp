// Usar caracteres especiales en consola C++
// Se requiere usar locale.h

#include <iostream>
#include <locale.h>
using namespace std;

int main(){
    setlocale(LC_ALL, ""); 

    wstring numero;
    wcout << L"Ingrese un número: "; 
    wcin >> numero;

    return 0;
}
