#include <funcionalidades.h>

int charToInt(char* cadena){

    /*
     * Conversor de caracter a entero
     * Cabe decir que esta funcion hace lo mismo que uno de los problemas sin embargo se separó para mayor orden
     *
     * Variables, constantes y arreglos.
     * cadena: cadena de caracteres númericos.
     *
     * Retorno:
     * resultado*signo: cadena de caracteres casteada a entero con su respectivo signo.
    */

    int resultado = 0;
    char* punteroIterador = cadena;
    int signo = 1;

    if(*punteroIterador == '-'){
        signo = -1;
    }

    while(*punteroIterador != '\0'){
        if(*punteroIterador >= '0' && *punteroIterador <= '9'){
            resultado = resultado * 10 + (*punteroIterador - '0');
        }
        punteroIterador ++;
    }

    return resultado * signo;

}



string charToBinary(char caracter) {

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

int binaryToInt(string binary){
    int valorDecimal = 0;
    int lsb = 7;
    char posCaracter[] = "\0";

    for(int i = 0; i<8; i++){
        posCaracter[0] = binary[i];
        valorDecimal += charToInt(posCaracter)*pow(2,lsb);
        lsb --;
    }

    return valorDecimal;


}


char* binaryToArray(string binario){
    int size = binario.length() / 8;
    char* array = genDinamicCharArray(size);
    string subcadena = "";
    int pos = 0;

    for(int i = 8; i <= binario.length(); i+=8){
        subcadena = slicing(binario,i-8,i);
        array[pos] = char(binaryToInt(subcadena));
        pos ++;
    }

    array[size] = '\0';
    return array;

}



void makeFile(const string ruta = ""){
    fstream file(ruta, ios::out);

    if(!file){
        cout << "No se pudo crear el archivo" << endl;
    }
    else {
        cout << "Se ha creado exitosamente el archivo" << endl;
    }


}

void FileToArray(char* array, const string ruta = "") {
    fstream file;
    int i = 0;
    char letra;
    file.open(ruta.c_str());

    if (file.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else {
        while (file.get(letra)) {
            if (letra != '\n' && letra != ' ') {
                array[i] = letra;
                i++;
            }
        }
        array[i] = '\0';
    }

    file.close();
}



void fileToString(string& str, const string ruta = ""){
    fstream file;
    char letra;
    int i = 0;

    file.open(ruta.c_str());
    if (file.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    }
    else{
        while (file.get(letra)){
            if (letra != '\n' && letra != ' ') {
                str += letra;
                i++;
            }

        }
    }
    file.close();
}


int contChars(const string ruta = ""){
    fstream file;
    char letra;
    int cont = 0;

    file.open(ruta.c_str());
    while (file.get(letra)){
       cont ++;
    }
    return cont;
}


int lenChar(char* cadena){

    /*
     * Contador de longitud de un arreglo caracteres
     *
     * Variables, constantes y arreglos.
     * cadena: arreglo de caracteres.
     *
     * Retorno:
     * len: longitud de la cadena.
    */

    int len = 0;
    while(cadena[len] != '\0'){
       len ++;
    }

    return len;

}

char* genDinamicCharArray(int size){
    char* arrayC = new char[size];
    return arrayC;
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




void write_file(string name, string info){
    fstream file;
    file.open(name,ios::out);
    file << info;
    file.close();
}
