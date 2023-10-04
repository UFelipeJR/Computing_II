#ifndef BANK_H
#define BANK_H
#endif // BANK_H
#include <iostream>
#include <string.h>
#include <funcionalidades.h>

using namespace std;

void bankSession(string,string);
bool uaccess(string, string, string, string**);
void adminAccess(string**,int,string);
void userAcces(string**,int);
void menu_principal();
