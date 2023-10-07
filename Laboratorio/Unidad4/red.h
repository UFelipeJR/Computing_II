#ifndef RED_H
#define RED_H

#include <iostream>|
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;

class red
{

private:
    int cantEnrutador = 0;

public:
    red();
    red(int _cantEnrutadores);
    int getCantEnrutador() const;
    void setCantEnrutador(int newCantEnrutador);
};

#endif // RED_H
