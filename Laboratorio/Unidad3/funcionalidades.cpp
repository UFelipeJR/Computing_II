#include <funcionalidades.h>
#include <codecs.h>


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
}


string displaceBitGOD(string bit){
    string aux = "";
    int indice = 0;
    int n = bit.length();

    for (int i = 0; i < n; i++) {
        indice = (i - 1 + n) % n;
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
    delete[] a;
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



string convertArray(string** array, string ruta, int mode){
    int columnas = 0;

    if(mode == 1){
        columnas = countCols(ruta)+1;
    }
    else if(mode == 2){
        columnas = countCols(ruta)-1;
    }
    else{
        columnas = countCols(ruta);
    }

    string strucTOf = "";

    for (int fila = 0; fila < 5; ++fila) {
        strucTOf += ":";
        for (int columna = 0; columna < columnas; ++columna) {
            strucTOf += array[fila][columna];
            strucTOf += ":";
        }
            strucTOf += "\n";
    }
    strucTOf.pop_back();

    return strucTOf;

}

string correcion(string origen, string destino, int seed){
    int len = (read_fileAlterno(origen,1).length())*8;
    string a = metodo1(seed,origen);

    return a.substr(0,len);

}


int countCols(string ruta){

    string** strucT(string ruta);
    int cont = 0;

    string* a = splitCriollo(ruta);

    while(a[cont] != "\n"){
        cont ++;
    }

    delete[] a;
    return cont;
}


string** deleteCol(string ruta, string user){
    int contColumnas = countCols(ruta);
    int colAssign = 0;
    string** array = strucT(ruta);

    string** newArray = new string *[5];

    for(int i = 0; i<5;i++){
        newArray[i] = new string[contColumnas-1];
    }

    for(int i = 0; i < contColumnas; i++){
        if(array[0][i] == user){
            colAssign = i;
            break;
        }
    }


    for(int i = 0; i<5;i++){
        for(int j = 0; j < contColumnas; j++){
            if( j != colAssign){
                if(j <= colAssign){
                    newArray[i][j] = array[i][j];
                }
                else{
                    newArray[i][j-1] = array[i][j];
                }

            }
        }
    }

    return newArray;

}

string** addCol(string ruta){
    int contColumnas = countCols(ruta);
    int colAssign = 0;
    string** structA = strucT(ruta);

    string** newArray = new string *[5];

    for(int i = 0; i<5;i++){
        newArray[i] = new string[contColumnas+1];
    }

    for(int i = 0; i<5;i++){
        for(int j = 0; j < contColumnas; j++){
            newArray[i][j] = structA[i][j];
        }
    }

    cout << "Ingrese el nombre de usuario: " << endl;
    cin >> newArray[0][contColumnas];

    cout << "Ingrese el documento de identidad: " << endl;
    cin >> newArray[1][contColumnas];

    cout << "Ingrese la clave de usuario: " << endl;
    cin >> newArray[2][contColumnas];

    newArray[3][contColumnas] = "0";

    cout << "Ingrese el saldo del usuario:: " << endl;
    cin >> newArray[4][contColumnas];


    return newArray;
}


int posColumna(string ruta,string** estructura, string user){
    int col = countCols(ruta);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < col; j++){
            if(estructura[i][j] == user){
                return j;
            }
        }
    }
}

void decodiWrite(string origen, string destino){
    string decodi = decodificador2(4,origen);
    write_file(destino,translateSemiCoded(decodi),1);
}


string printUsers(string ruta){
    string** a = strucT(ruta);
    int opcion = 1;
    int contColumnas = countCols(ruta);

    cout << "Usuarios Disponibles: " << endl;
    for(long long int j = 0; j < contColumnas; j++){
        cout << opcion << "." << a[0][j] << " " << a[1][j] << endl;
        opcion ++;
    }

    while(true){
        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        if(opcion > 0 && opcion <= contColumnas){
            break;
        }
        else{
            cout << "Opcion invalida: " << endl;
        }
    }
    return a[0][opcion-1];

}
