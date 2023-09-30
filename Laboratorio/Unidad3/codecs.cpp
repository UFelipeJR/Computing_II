#include <codecs.h>
#include <funcionalidades.h>


string metodo1(int seed, string filePath){

    int residuo = 0;

    string decodedBinary = genChainBinary(filePath,1);
    string codedBinary = "";

    string subcadenaAnterior = "";
    string subcadenaActual = "";
    string subcadenaAjustada = "";

    if(decodedBinary.length()<= seed){
        codedBinary += bitInverter(decodedBinary);
        return codedBinary;

    }

    if(decodedBinary.length() % seed != 0){
        residuo = decodedBinary.length() % seed;
        subcadenaAjustada = slicing(decodedBinary,0,decodedBinary.length()-residuo);
    }

    else{
        subcadenaAjustada += decodedBinary;
    }

    subcadenaActual = slicing(subcadenaAjustada,0,seed);
    codedBinary += bitInverter(subcadenaActual);

    if(residuo == 0){
        for(int i = 0;  i <= (decodedBinary.length() - 2*seed); i+=seed){
            subcadenaAnterior = slicing(decodedBinary,i,i+seed);
            subcadenaActual = slicing(decodedBinary,i+seed,i+2*seed);
            codedBinary += genCodi(subcadenaAnterior,subcadenaActual);
        }

    }
    else{
        subcadenaActual = slicing(decodedBinary,decodedBinary.length()-residuo,decodedBinary.length());
        subcadenaAnterior = slicing(decodedBinary,decodedBinary.length()-2*seed,decodedBinary.length()-seed);
        codedBinary += genCodi(subcadenaAnterior,subcadenaActual);
    }

    return codedBinary;

}


string decodificador1(int seed, string filePath){

    int residuo = 0;

    string codedBinary = genChainBinary(filePath,2);

    string subcadenaAnterior = "";
    string subcadenaActual = "";
    string subcadenaAjustada = "";
    string decodedBinary = "";

    if(decodedBinary.length()<= seed){
        decodedBinary += bitInverter(codedBinary);
        return decodedBinary;

    }

    if(codedBinary.length() % seed != 0){
        residuo = codedBinary.length() % seed;
        subcadenaAjustada = slicing(codedBinary,0,codedBinary.length()-residuo);
    }
    else{
        subcadenaAjustada += codedBinary;
    }


    subcadenaActual = slicing(subcadenaAjustada,0,seed);
    decodedBinary += bitInverter(subcadenaActual);

    if(residuo == 0){
        for(int i = 0;  i <= (codedBinary.length() - 2*seed); i+=seed){
            subcadenaAnterior = slicing(decodedBinary,i,i+seed);
            subcadenaActual = slicing(codedBinary,i+seed,i+2*seed);
            decodedBinary += genCodi(subcadenaAnterior,subcadenaActual);

        }
    }
    else{
        subcadenaActual = slicing(codedBinary,codedBinary.length()-residuo,codedBinary.length());
        subcadenaAnterior = slicing(decodedBinary,decodedBinary.length()-2*seed,decodedBinary.length()-seed);
        decodedBinary += genCodi(subcadenaAnterior,subcadenaActual);
    }

    return decodedBinary;

}


