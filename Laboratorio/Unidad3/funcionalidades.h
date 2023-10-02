    #ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>

using namespace std;

char* read_file(string,int);
string read_fileAlterno(string,int);
string charToBinary(char);
string genChainBinary(string,int);
string slicing(string, int, int);
string bitInverter(string cadena);
int contUnosCeros(char, string);
string genCodi(string, string);
char* stringBinaryToArray(string);
char* genDinamicCharArray(int);
int binaryToInt(string);
double pow(int,int);
void write_file(string,string,int);
string displaceBitGOD(string);
string translateSemiCoded(string);
string antiDisplaceBit(string,int);
int* posLine(char*, char, int&);
int contApar(char*, char);
string* splitCriollo(string);
string** strucT(string);
int countCols(string);
string convertArray(string**, string);
string correcion(string,string,int);
string** deleteCol(string,string);
string** addCol(string);

#endif // FUNCIONALIDADES_H
