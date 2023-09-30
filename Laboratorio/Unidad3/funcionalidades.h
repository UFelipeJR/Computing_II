#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>

using namespace std;

//string read_file(string,int);
char* read_file(string,int);

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

#endif // FUNCIONALIDADES_H
