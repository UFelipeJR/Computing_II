#include <funcionalidades.h>
#include <codecs.h>
#include <bank.h>



unsigned char* genDinamicCharArrayP(int size){
    unsigned char* arrayC = new unsigned char[size];
    return arrayC;
}

unsigned char* read_filePrueba(string name, int mode){

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

    unsigned char* array = genDinamicCharArrayP(file.tellg());

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


unsigned int obtenerLongitud(const unsigned char* cadena) {
    unsigned int longitud = 0;

    while (*cadena != '\0') {
        longitud++;
        cadena++;
    }

    return longitud;
}

string genChainBinaryAlterno(string ruta, int modo){
    unsigned char* chainOrigin = read_filePrueba(ruta,2);
    string chainBinary = "";

    for(int i = 0; i < obtenerLongitud(chainOrigin); i++){
        chainBinary += charToBinary(chainOrigin[i]);
    }
    return chainBinary;
}

int main(){
    //string prueba = "../Unidad3/Prueba/prueba.txt";
    //string destino = "../Unidad3/Prueba/prueba.dat";
    //string p = "";
    menu_principal();
    return 0;
}



