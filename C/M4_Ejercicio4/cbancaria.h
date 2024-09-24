#ifndef CBANCARIA_H
#define CBANCARIA_H
#include <string>

class CBancaria
{
private:
    std::string titular;
    double saldo;
    double interes;

public:
    CBancaria(const std::string &titular, double saldo, double interes); // const std::string& titular es una referencia constante a un string para evitar copias innecesarias
    void ingresar(double cantidad);
    bool retirar(double cantidad);
    double calcular_beneficio() const;
    void visualizar() const;
};

#endif