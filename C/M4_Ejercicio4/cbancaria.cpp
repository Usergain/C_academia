#include <iostream>
#include "cbancaria.h"
#include <string>

using namespace std;

CBancaria::CBancaria(const std::string &titular, double saldo, double interes)
{
    this->titular = titular;
    this->saldo = saldo;
    this->interes = interes;
}

void CBancaria::ingresar(double cantidad)
{
    saldo += cantidad;
}

bool CBancaria::retirar(double cantidad)
{
    if (cantidad <= saldo)
    {
        saldo -= cantidad;
        return true;
    }
    else
    {
        return false;
    }
}

double CBancaria::calcular_beneficio() const
{
    return saldo + ((saldo * interes)/100);
}

void CBancaria::visualizar() const
{
    cout << "Titular: " << titular << endl;
    cout << "Saldo: " << saldo << endl;
    cout << "Interés: " << interes << endl;
    cout << "Beneficio: " << calcular_beneficio() << endl;
}
