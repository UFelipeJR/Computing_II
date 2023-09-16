#include <funcionalidades.h>


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
    ifstream file;
    int i = 0;
    char letra;
    file.open(ruta.c_str());

    if (file.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
    } else {
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



int contChars(const string ruta = ""){
    ifstream file;
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

    int nuevaLongitud = indiceFin - indiceInicio;
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
