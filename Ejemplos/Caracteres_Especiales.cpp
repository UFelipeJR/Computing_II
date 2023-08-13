#include <iostream>
#include <locale.h>
using namespace std;

int main(){
    setlocale(LC_ALL, ""); // Configura la localización actual

    wstring numero;
    wcout << L"Ingrese un número: "; 
    wcin >> numero;

    return 0;
}
