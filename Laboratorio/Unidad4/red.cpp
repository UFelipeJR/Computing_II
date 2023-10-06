#include "red.h"

red::red()
{

}

red::red(int _cantEnrutadores){
    cantEnrutador = _cantEnrutadores;
}

int red::getCantEnrutador() const
{
    return cantEnrutador;
}

void red::setCantEnrutador(int newCantEnrutador)
{
    cantEnrutador = newCantEnrutador;
}
