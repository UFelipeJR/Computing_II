#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

string charToBinary(char caracter);
void FileToArray(char*, const string);
void makeFile(const string);
int contChars(const string);
char* genDinamicCharArray(int);
int lenChar(char*);
string slicing(string, int, int);
void write_file(string, string);

#endif // FUNCIONALIDADES_H
