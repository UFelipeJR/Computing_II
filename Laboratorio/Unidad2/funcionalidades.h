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
<<<<<<< HEAD
void fillMatrizRandom(int**, int, int);
void rotatedMatriz(int** ,int ,int , int );
unsigned long long factorial(int n);
int divisoresSum(int);
=======
void rotatedMatriz(int**,int ,int, int);
unsigned long long factorial(int);
long long int n_permutacion_lexicografica(int);
int lenChar(char*);
int NearbyMulti(int, int);
char* slicing(char*, int, int);
int charToInt(char* cadena);
int contDigits(int);
char** llenarMatrizCine();
void printMatrizCine(char** arreglo);
void cleanMatrizCine(char filas, char **matriz);
void fillMatrizRandomN(int** matriz, int filas, int columnas);
int divisoresSum(int num);
void sumAmigablesMin(int limite);
>>>>>>> c8e430a38acc58b77930f8fa7a6814fa1a5fe0cd

#endif // FUNCIONALIDADES_H
