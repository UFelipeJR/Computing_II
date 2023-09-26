#ifndef CODIFICADORES_H
#define CODIFICADORES_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <funcionalidades.h>


using namespace std;

void arrayToBinary(string&,char*);
string metodo1(int, string);
string metodo2(int, string);
string bitInverter(string);
int contUnosCeros(char, string);
string invertedNBits(int, string);
string genCodi(string, string);
string displaceBit(string);
string decodificador1(int, string);
string antiGen(string, string);
string decodificador2(int, string);
string antiDisplaceBit(string);
string DisplaceBitGOD(string);
string antiDisplaceBit(string);
char* translateSemiCoded(string);

#endif // CODIFICADORES_H
