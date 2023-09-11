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

#endif // FUNCIONALIDADES_H
