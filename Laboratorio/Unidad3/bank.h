#ifndef BANK_H
#define BANK_H
#endif // BANK_H
#include <iostream>
#include <string.h>
#include <funcionalidades.h>

using namespace std;

void bankSession(string,string);
bool uaccess(string, string, string, string**);
int posColumna(string**, string);
void adminAccess(string** estructura, int j);
void userAcces(string**, int);
