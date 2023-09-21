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
    string nueva = "";

    unos = contUnosCeros('1',anterior);
    ceros = contUnosCeros('0',anterior);


    if(unos == ceros){
        nueva = bitInverter(actual);
        return nueva;
    }

    else if(ceros > unos){
        nueva = invertedNBits(2,actual);
        return nueva;

    }

    else if(unos > ceros){
        nueva = invertedNBits(3,actual);
        return nueva;
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

string antiGen(string anterior, string actual){

    int unos = 0;
    int ceros = 0;
    string nueva = "";

    unos = contUnosCeros('1',anterior);
    ceros = contUnosCeros('0',anterior);


    if(unos == ceros){
        nueva = bitInverter(actual);
        return nueva;
    }

    else if(ceros > unos){
        nueva = invertedNBits(2,actual);
        return nueva;

    }

    else if(unos > ceros){
        nueva = invertedNBits(3,actual);
        return nueva;
    }

}


string decodificador1(int seed, string filePath){
    string codedBinary = "";
    string subcadenaAnterior = "";
    string subcadenaActual = "";
    string subcadenaAjustada = "";
    string decodedBinary = "";
    int residuo = 0;
    fileToString(codedBinary, filePath);


    if(codedBinary.length() % seed != 0){
        residuo = codedBinary.length() % seed;
        subcadenaAjustada = slicing(codedBinary,0,codedBinary.length()-residuo);
    }
    else{
        subcadenaAjustada += codedBinary;
    }


    subcadenaActual = slicing(subcadenaAjustada,0,seed);
    decodedBinary += bitInverter(subcadenaActual);


    for(int i = 0;  i <= (codedBinary.length() - 2*seed); i+=seed){
        subcadenaAnterior = slicing(codedBinary,i,i+seed);
        subcadenaActual = slicing(codedBinary,i+seed,i+2*seed);
        decodedBinary += antiGen(subcadenaAnterior,subcadenaActual);

    }

    cout << decodedBinary << endl;


    if(residuo != 0){
        //subcadenaActual = slicing(codedBinary,codedBinary.length()-residuo,codedBinary.length());
        //subcadenaAnterior = slicing(codedBinary,codedBinary.length()-residuo*2,codedBinary.length()-residuo);
        //decodedBinary += genCodi(subcadenaAnterior,subcadenaActual);
        //cout << genCodi(subcadenaAnterior,subcadenaActual) << endl;

    }

    return decodedBinary;

}

