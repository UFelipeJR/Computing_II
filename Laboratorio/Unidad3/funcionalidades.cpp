#include <funcionalidades.h>



string read_fileAlterno(string name, int mode){
    unsigned long long tam;
    fstream file;
    string data;

    if(mode == 1){
        file.open(name,ios::in | ios::ate);
    }
    else{
        file.open(name,ios::in | ios::ate | ios::binary);
    }


    if(file.is_open()){
        tam = file.tellg();
        file.seekg(0);
        for(unsigned long long i=0;i<tam;i++){
            data.push_back(file.get());
        }
    }

    file.close();
    return data;
}


char* read_file(string name, int mode){

    unsigned long long tam;
    fstream file;

    switch(mode){
        case 1:
            file.open(name,ios::in | ios::ate);
            break;
        case 2:
            file.open(name,ios::in | ios::ate | ios::binary);
            break;
    }

    char* array = genDinamicCharArray(file.tellg());

    if(file.is_open()){
        tam = file.tellg();
        file.seekg(0);
        for(unsigned long long i=0;i<tam;i++){
            array[i] = file.get();
        }
        array[tam] = '\0';
    }

    file.close();

    return array;

}


string charToBinary(char caracter){

    string chainBinaryInverse = "";
    string Binary = "";
    int bitMissing = 0;
    int valAscii = int(caracter);
    int residuo = 0;

    while (valAscii > 0) {
        residuo = valAscii % 2;
        chainBinaryInverse += to_string(residuo);
        valAscii /= 2;
    }


    bitMissing = 8 - chainBinaryInverse.length();

    if (chainBinaryInverse.length() != 8) {
        for (int i = 0; i < bitMissing; i++) {
            Binary += '0';
        }
    }

    for (int i = chainBinaryInverse.length() - 1; i >= 0; i--) {
        Binary += chainBinaryInverse[i];
    }


    return Binary;
}

string genChainBinary(string ruta, int modo){
    char* chainOrigin = read_file(ruta,modo);
    string chainBinary = "";

    for(int i = 0; i < strlen(chainOrigin); i++){
        chainBinary += charToBinary(chainOrigin[i]);
    }
    return chainBinary;
}

string slicing(string cadenaOriginal, int indiceInicio, int indiceFin){

    /*
     * Slicing de arreglos de caracteres
     *
     * Variables, constantes y arreglos.
     * cadenaOriginal: cadena de la cuál se extraerá la subcadena.
     * indiceInicio: extremo inferior para la subcadena.
     * indiceFin: extremo superior para la subcadena.
     *
     * Retorno:
     * nuevaCadena: subcadena generada en base a los indices.
    */

    string nuevaCadena = "";
    int iGen = 0;

    for (int i = indiceInicio; i < indiceFin; i++) {
       nuevaCadena += cadenaOriginal[i];
       iGen ++;
    }


    return nuevaCadena;

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

int contUnosCeros(char parametro, string subcadena){
    int cont = 0;
    for(int i = 0; i<subcadena.length();i++){
        if(subcadena[i] == parametro){
            cont += 1;
        }
    }

    return cont;
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

double pow(int base, int exponente) {

    if (exponente == 0) {
        return 1;
    }

    else {
        return base * pow(base, exponente - 1);
    }
}


int binaryToInt(string binary){
    int valorDecimal = 0;
    int lsb = 7;

    for(int i = 0; i<8; i++){
        if(binary[i] == '1'){
            valorDecimal += pow(2,lsb);
        }
        lsb --;
    }


    return valorDecimal;
}

char* genDinamicCharArray(int size){
    char* arrayC = new char[size];
    return arrayC;
}

char* stringBinaryToArray(string cadena){
    long long int size = cadena.length()/8;
    char* arregloC = genDinamicCharArray(size);
    long long int extremoInf = 0;
    long long int extremoSup = 8;


    for(int i = 0; extremoSup <= size*8; i++){
        //arregloC[i] = char();
        arregloC[i] = static_cast<char>(binaryToInt(slicing(cadena, extremoInf, extremoSup)));
        extremoInf += 8;
        extremoSup += 8;
    }

    arregloC[size] = '\0';

    return arregloC;

}

void write_file(string name, string info ,int mode){
    fstream file;
    if(mode == 1){
        file.open(name,ios::out);
    }
    else{
        file.open(name, std::ios::out | std::ios::binary);
    }

    file << info;
    file.close();
    cout << "Se ha escrito correctamente " << endl;
}


string displaceBitGOD(string bit){
    string aux = "";
    int indice = 0;
    int n = bit.length();

    for (int i = 0; i < n; i++) {
        int indice = (i - 1 + n) % n;
        aux += bit[indice];
    }

    return aux;
}


string antiDisplaceBit(string bit, int seed){
    string aux = bit;
    for(int i = 0; i < seed-1; i++){
        aux = displaceBitGOD(aux);
    }
    return aux;
}



string translateSemiCoded(string cadenaOri){
    long long size = cadenaOri.length();
    string cadena = "";


    for(int i = 0; i<size;i+=8){
         cadena += char(binaryToInt(slicing(cadenaOri,i,i+8)));

    }

    return cadena;
}


int contApar(char* array, char caracter) {
    int size = 0;
    for (int i = 0; i < strlen(array); i++) {
        if (array[i] == caracter) {
            size++;
        }
    }
    return size;
}

int* posLine(char* array, char caracter, int& len) {
    int size = contApar(array, caracter);
    int posAux = 0;
    int* pos = new int[size];
    len = size;

    for (int i = 0; i < strlen(array); i++) {
        if (array[i] == caracter) {
            pos[posAux] = i;
            posAux++;
        }
    }

    return pos;
}


string translateToString(char* array, int longitud){
    string cadena = "";
    for(int i = 0; i<longitud; i++){
        cadena += array[i];
    }
    return cadena;
}


string* splitCriollo(string filePath){
    int longitud = 0;
    char* prueba = read_file(filePath,1);
    int* a = posLine(prueba,':', longitud);
    string cadena = translateToString(prueba,strlen(prueba));

    int posArray = 0;
    int indice0 = 0;
    int indice1 = 1;

    string* arregloDeStrings = new string[(longitud-1)*(longitud-1)];

    while(indice1 != longitud){
    arregloDeStrings[posArray] = slicing(cadena,a[indice0]+1,a[indice1]);
    indice0 ++;
    indice1 ++;
    posArray++;
    }



    return arregloDeStrings;

}

string** strucT(string ruta){
    int cont = 0;
    int pos = 0;

    string* a = splitCriollo(ruta);

    while(a[cont] != "\n"){
        cont ++;
    }

;
    string* arregloProvi = new string[cont*5];


    for(int i = 0; !a[i].empty() ; i++){
        if(a[i] != "\n"){
            arregloProvi[pos] = a[i];
            pos ++;
        }
    }

    //Matriz Dinamica

    string** matriz = new string*[5];

    for(int i = 0; i<5;i++){
        matriz[i] = new string[cont];

    }

    pos = 0;
    for(int i = 0; i<5;i++){
        for(int j = 0; j<cont;j++){
            matriz[i][j] = arregloProvi[pos];
            pos ++;
        }
    }


    delete[] a;
    delete[] arregloProvi;
    return matriz;

}

int countCols(string ruta){

    string** strucT(string ruta);
    int cont = 0;

    string* a = splitCriollo(ruta);

    while(a[cont] != "\n"){
        cont ++;
    }

    return cont;
}
