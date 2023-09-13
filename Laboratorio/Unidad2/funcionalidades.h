#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char* genDinamicRandomAlphabet(const int);
int lenChar(char* cadena);
char* genDinamicCharArray(const int);
int contDigits(int n);
char upperChar(char);
int NearbyMulti(int, int);
char* slicing(char*, int, int);
int charToInt(char*);
bool checkRoman(char*);
int equivRoman(char);
char** llenarMatrizCine();
void printMatrizCine(char**);
int** genDinamicMatriz(int,int);
void cleanMemoryMatrizmxn(int, int **);
void fillMatriz(int**, int , int );
void printMatriz(int** , int, int);
void fillMatrizRandom(int**, int, int);
void rotatedMatriz(int** ,int ,int , int );
unsigned long long factorial(int n);
int divisoresSum(int);

#endif // FUNCIONALIDADES_H
