#ifndef MOTOR_H
#define PUNTO_H

#include <iostream>

class Motor
{
private:
    int estado;
    int regimen;

public:
    Motor();
    Motor(int regimen);

    int getEstado();
    int getRegimen();
    bool aumentarRegimen();
    bool reducirRegimen();
    void parada();
};

#endif