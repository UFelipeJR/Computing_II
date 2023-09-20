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


string invertedNBits(int nBits, string subcadena) {
    int indicador = 1;
    int i = 0;
    string nuevaCadena = "";

    for(int i = 0; i != subcadena.length();i++){
        if(indicador == nBits){
            if(subcadena[i] == '0'){
                nuevaCadena += '1';
            }
            else{
                nuevaCadena += '0';
            }
            indicador = 0;
        }
        else{
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


    if(unos == ceros){
        return bitInverter(actual);
    }

    else if(ceros > unos){
        return invertedNBits(2,actual);

    }

    else if(unos < ceros){
        return invertedNBits(3,actual);
    }

}



string displaceBit(string bit) {
    string cadenaCodificada = "";

    if (bit.length() < 2) {
        return bit;
    }

    cadenaCodificada += bit[bit.length() - 1];

    for (int i = 0; i < bit.length() - 1; i++) {
        cadenaCodificada += bit[i];
    }

    return cadenaCodificada;
}



string metodo1(int seed, string filePath){
    char* arreglo = genDinamicCharArray(contChars(filePath));
    int residuo = 0;
    string decodedBinary = "";
    string codedBinary = "";
    string subcadenaAnterior = "";
    string subcadenaActual = "";
    string subcadenaAjustada = "";


    FileToArray(arreglo,filePath);
    arrayToBinary(decodedBinary,arreglo);

    if(decodedBinary.length() % seed != 0){
        residuo = decodedBinary.length() % seed;
        subcadenaAjustada = slicing(decodedBinary,0,decodedBinary.length()-residuo);
    }

    else{
        subcadenaAjustada += decodedBinary;
    }

    subcadenaActual = slicing(subcadenaAjustada,0,seed);
    codedBinary += bitInverter(subcadenaActual);

    for(int i = 0;  i <= (decodedBinary.length() - 2*seed); i+=seed){
        subcadenaAnterior = slicing(decodedBinary,i,i+seed);
        subcadenaActual = slicing(decodedBinary,i+seed,i+2*seed);
        codedBinary += genCodi(subcadenaAnterior,subcadenaActual);
    }


    if(residuo != 0){
        subcadenaActual = slicing(decodedBinary,decodedBinary.length()-residuo,decodedBinary.length());
        subcadenaAnterior = slicing(decodedBinary,decodedBinary.length()-residuo*2,decodedBinary.length()-residuo);
        codedBinary += genCodi(subcadenaAnterior,subcadenaActual);
    }

    delete[] arreglo;
    return codedBinary;

}


string metodo2(int seed, string filePath){
    int residuo = 0;
    char* arreglo = genDinamicCharArray(contChars(filePath));
    string decodedBinary = "";
    string subcadenaAjustada = "";
    string codedBinary = "";


    FileToArray(arreglo,filePath);
    arrayToBinary(decodedBinary,arreglo);

    if(decodedBinary.length() % seed != 0){
        residuo = decodedBinary.length() % seed;
        subcadenaAjustada = slicing(decodedBinary,0,decodedBinary.length()-residuo);
    }

    else{
        subcadenaAjustada += decodedBinary;
    }


    for(int i = 0; i < subcadenaAjustada.length(); i+=seed){
        codedBinary += displaceBit(slicing(decodedBinary,i,i+seed));
    }

    if(residuo != 0){
        codedBinary += displaceBit(slicing(decodedBinary,decodedBinary.length()-residuo,decodedBinary.length()));

    }
    cout << codedBinary << endl;

}


string decodificador1(int seed, string filePath){
    string texto = "";
    string subcadenaAjustada = "";
    string subcadenaAnterior = "";
    string subcadenaActual = "";
    string decodedBinary = "";
    int residuo = 0;
    fileToString(texto, filePath);


    if(texto.length() % seed  != 0){
        residuo = texto.length() % seed;
        subcadenaAjustada = slicing(texto,0,texto.length()-residuo);
    }
    else{
        subcadenaAjustada += texto;
    }

    subcadenaActual = slicing(subcadenaAjustada,0,seed);
    cout << subcadenaActual << endl;
    decodedBinary += bitInverter(subcadenaActual);

    for(int i = 0;  i <= (texto.length() - 2*seed); i+=seed){
        subcadenaAnterior = slicing(texto,i,i+seed);
        subcadenaActual = slicing(texto,i+seed,i+2*seed);
        //decodedBinary += subcadenaActual;

    }

    cout << decodedBinary << endl;

}
