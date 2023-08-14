#Usar caracteres especiales en consola C++

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
