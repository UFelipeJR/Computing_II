#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>

using namespace std;

int charToInt(char*);
string charToBinary(char caracter);
char* binaryToArray(string);
int binaryToInt(string);
void FileToArray(char*, const string);
void makeFile(const string);
int contChars(const string);
char* genDinamicCharArray(int);
int lenChar(char*);
string slicing(string, int, int);
void write_file(string, string);
void fileToString(string&, const string);


#endif // FUNCIONALIDADES_H
