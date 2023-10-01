#include <codecs.h>
#include <funcionalidades.h>


string metodo1(int seed, string filePath){

    string decodedBinary = genChainBinary(filePath,1), codedBinary = "";
    string subCadenaAnterior = "", subCadenaActual = "", subCadenaAjustada = "";
    int residuo = 0;

    if(decodedBinary.length() <= seed){
        codedBinary = bitInverter(decodedBinary);
        return codedBinary;
    }

    else if(decodedBinary.length() % seed != 0){
        residuo = decodedBinary.length() % seed;
        subCadenaAjustada = decodedBinary.substr(0,decodedBinary.length()-residuo);
    }
    else{
        subCadenaAjustada = decodedBinary;
    }

    subCadenaActual = subCadenaAjustada.substr(0,seed);
    codedBinary += bitInverter(subCadenaActual);


    if(residuo < decodedBinary.length()-subCadenaAjustada.length()){
        subCadenaAnterior = subCadenaActual;
        subCadenaActual = decodedBinary.substr(codedBinary.length(),decodedBinary.length()-codedBinary.length());
        codedBinary += genCodi(subCadenaAnterior,subCadenaActual);
        return codedBinary;
    }



    for(long long unsigned int i = 0; i <= (decodedBinary.length() - residuo)-1; i+=seed){
        subCadenaAnterior = decodedBinary.substr(i, seed);
        subCadenaActual = decodedBinary.substr(i + seed, seed);
        codedBinary += genCodi(subCadenaAnterior,subCadenaActual);
        subCadenaAnterior = "";
        subCadenaActual = "";
    }


    if(residuo != 0){
        subCadenaAnterior = decodedBinary.substr(decodedBinary.length()-residuo-seed,seed);
        subCadenaActual = decodedBinary.substr(decodedBinary.length()-residuo, residuo);
        codedBinary += genCodi(subCadenaAnterior,subCadenaActual);
    }


    return codedBinary;

}

string decodificador1(int seed, string filePath){

    string decodedBinary = "", codedBinary = read_fileAlterno(filePath,2);
    string subCadenaAnterior = "", subCadenaActual = "", subCadenaAjustada = "";
    int residuo = 0;

    if(codedBinary.length() <= seed){
        decodedBinary = bitInverter(codedBinary);
        return decodedBinary;
    }

    else if(codedBinary.length() % seed != 0){
        residuo = codedBinary.length() % seed;
        subCadenaAjustada = codedBinary.substr(0,codedBinary.length()-residuo);
    }
    else{
        subCadenaAjustada = codedBinary;
    }

    subCadenaActual = subCadenaAjustada.substr(0,seed);
    decodedBinary += bitInverter(subCadenaActual);


    if(residuo < codedBinary.length()-subCadenaAjustada.length()){
        subCadenaAnterior = decodedBinary;
        subCadenaActual = codedBinary.substr(decodedBinary.length(),codedBinary.length()-decodedBinary.length());
        codedBinary += genCodi(subCadenaAnterior,subCadenaActual);
        return codedBinary;
    }



    for(long long unsigned int i = 0; i <= (codedBinary.length() - residuo)-1; i+=seed){
        subCadenaAnterior = decodedBinary.substr(i, seed);
        subCadenaActual = codedBinary.substr(i + seed, seed);
        decodedBinary += genCodi(subCadenaAnterior,subCadenaActual);
        subCadenaAnterior = "";
        subCadenaActual = "";
    }



    if(residuo != 0){
        subCadenaAnterior = decodedBinary.substr(decodedBinary.length()-residuo-seed,seed);
        subCadenaActual = codedBinary.substr(codedBinary.length()-residuo, residuo);
        codedBinary += genCodi(subCadenaAnterior,subCadenaActual);
    }


    return decodedBinary;
}

string metodo2(int seed, string filePath){

    string decodedBinary = genChainBinary(filePath,1), codedBinary = "";
    string subCadenaActual = "", subCadenaAjustada = "";
    int residuo = 0;

    if(decodedBinary.length() <= seed){
        codedBinary = displaceBitGOD(decodedBinary);
        return codedBinary;
    }

    else if(decodedBinary.length() % seed != 0){
        residuo = decodedBinary.length() % seed;
        subCadenaAjustada = decodedBinary.substr(0,decodedBinary.length()-residuo);
    }
    else{
        subCadenaAjustada = decodedBinary;
    }

    for(long long unsigned int i = 0; i < subCadenaAjustada.length();i+=seed){
        codedBinary += displaceBitGOD(decodedBinary.substr(i,seed));
    }

    if(residuo != 0){
        subCadenaActual = decodedBinary.substr(subCadenaAjustada.length(),residuo);
        codedBinary += displaceBitGOD(subCadenaActual);
    }

}

string decodificador2(int seed, string filePath){
    string decodedBinary = "", codedBinary = read_fileAlterno(filePath,2);
    string subCadenaActual = "", subCadenaAjustada = "";
    int residuo = 0;

    if(codedBinary.length() <= seed){
        decodedBinary = antiDisplaceBit(codedBinary,codedBinary.length());
        return decodedBinary;
    }

    else if(codedBinary.length() % seed != 0){
        residuo = codedBinary.length() % seed;
        subCadenaAjustada = codedBinary.substr(0,codedBinary.length()-residuo);
    }
    else{
        subCadenaAjustada = codedBinary;
    }

    for(long long unsigned int i = 0; i < subCadenaAjustada.length();i+=seed){
        decodedBinary += antiDisplaceBit(codedBinary.substr(i,seed),seed);
    }

    if(residuo != 0){
        subCadenaActual = codedBinary.substr(subCadenaAjustada.length(),residuo);
        decodedBinary += antiDisplaceBit(subCadenaActual,residuo);

    }


    return decodedBinary;
}
