#include <codificadores.h>


void arrayToBinary(string &stringBin,char* array){

    for(int i = 0; i< lenChar(array) ; i++){
        stringBin += charToBinary(array[i]);
    }

}

string bitInverter(string cadena){
    string inverted = "";
    for(int i = 0; i < cadena.length();i++){
        if(cadena[i] == '0'){
            inverted += '1';
        }
        else{
            inverted += '0';
        }
    }

    return inverted;

}


int contUnosCeros(char parametro, string subcadena){
    int cont = 0;
    for(int i = 0; i<subcadena.length();i++){
        if(subcadena[i] == parametro){
            cont += 1;
        }
    }

    return cont;
}


string invertedNBits(int nBits, string subcadena){

    int indicador = 1;
    string nuevaCadena = "";

    for(int i = 0; i < subcadena.length(); i++){
        if(indicador == nBits){
            if(subcadena[i] == '0'){
                nuevaCadena += '1';
            }
            else{
                nuevaCadena += '0';
            }
            indicador = 1;
        }
        else {
            nuevaCadena += subcadena[i];
        }
        indicador++;
    }


    return nuevaCadena;
}


string genCodi(string anterior, string actual){

    int unos = 0;
    int ceros = 0;

    unos = contUnosCeros('1',anterior);
    ceros = contUnosCeros('0',anterior);

    //cout << anterior;
    //cout << " " << unos << " " << ceros << endl;


    if(unos == ceros){
        cout << actual << endl;
        cout << bitInverter(actual) << endl;
        return bitInverter(actual);
    }

    else if(ceros > unos){
        cout << actual << endl;
        cout << invertedNBits(2,actual) << endl;
        return invertedNBits(2,actual);

    }

    else if(unos < ceros){
        cout << actual << endl;
        cout << invertedNBits(3,actual) << endl;
        return invertedNBits(3,actual);
    }

}


void metodo1(int seed, string filePath){

    char* arreglo = genDinamicCharArray(contChars(filePath));

    string decodedBinary = "";
    string codedBinary = "";
    string subcadenaAnterior = "";
    string subcadenaActual = "";
    int unos = 0, ceros = 0;


    FileToArray(arreglo,filePath);
    arrayToBinary(decodedBinary,arreglo);
    cout << decodedBinary << endl;



    if(decodedBinary.length() % seed == 0){
        subcadenaActual = slicing(decodedBinary,0,seed);
        codedBinary += bitInverter(subcadenaActual);
        codedBinary += " ";

        for(int i = 0;  i <= decodedBinary.length() - 2*seed ; i+=seed){
            subcadenaAnterior = slicing(decodedBinary,i,i+seed);
            subcadenaActual = slicing(decodedBinary,i+seed,i+2*seed);

            unos = contUnosCeros('1',subcadenaAnterior);
            ceros = contUnosCeros('0',subcadenaAnterior);

            cout << "Division" << endl;
            genCodi(subcadenaAnterior,subcadenaActual);


        }


    }
    else{
        cout << decodedBinary.length() % seed;
    }

    cout << "La cadena codificada es: " << codedBinary << endl;

    delete[] arreglo;


}
