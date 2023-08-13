// Solución Trivial

// Crear la siguiente figura dado un número entero
// A           A
// AB         BA
// ABC       CBA
// ABCD     DCBA
// ABCDE   EDCBA
// ABCDEF FEDCBA
// ABCDEFGFEDCBA


//for (int i = 'A'; i < ('A' + n); i++) {
//    cout << static_cast<char>(i); 
//}


#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el valor de la base: ";
    cin >> n;

    int esp_blanco = (n * 2) - 3, letras = 1;

    for (int i = 0; i < n - 1; i++) {
        int j = 1, l = 0;

        while (j <= letras) {
            char letra = 'A' + j - 1;
            cout << letra;
            j += 1;
        }

        while (l < esp_blanco) {
            cout << " ";
            l += 1;
        }

        j -= 1;
        while (j >= 1) {
            char letra = 'A' + j - 1;
            cout << letra;
            j -= 1;
        }

        esp_blanco -= 2;
        letras += 1;

        cout << endl;
    }

    for (int i = 1; i < n + 1; i++) {
        char letra = 'A' + i - 1;
        cout << letra;
    }

    for (int i = n - 1; i != 0; i--) {
        char letra = 'A' + i - 1;
        cout << letra;
    }

    return 0;
}
