#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

char* genDinamicCharArray(const int);
char* genDinamicRandomAlphabet(const int);
char upperChar(char);
bool checkRoman(char* );
int equivRoman(char );
int** genDinamicMatriz(int,int);
void cleanMemoryMatrizmxn(int, int **);
void fillMatriz(int**, int , int );
void printMatriz(int** , int, int);
void rotatedMatriz(int**,int ,int, int);
unsigned long long factorial(int);
long long int n_permutacion_lexicografica(int);
int lenChar(char*);
int NearbyDivisor(int, int);
char* slicing(char*, int, int);
int charToInt(char* cadena);

#endif // FUNCIONALIDADES_H
