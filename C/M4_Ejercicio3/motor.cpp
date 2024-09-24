#include "motor.h"

Motor::Motor()
{
    estado = 0;
    regimen = 0;
}

Motor::Motor(int regimen)
{
    estado = (regimen == 0) ? 0 : 1; // Estado 0 = parado, 1= marcha
    this->regimen = regimen;
}

int Motor::getEstado()
{
    return estado;
}

int Motor::getRegimen()
{
    return regimen;
}

bool Motor::aumentarRegimen()
{
    if (regimen < 3)
    {
        regimen++;
        estado = 1; // en marcha
        return true;
    }
    else
    {
        return false;
    }
}

bool Motor::reducirRegimen()
{
    if (regimen > -3)
    {
        regimen--;
        estado = (regimen == 0) ? 0 : 1; // si se cumple esata condicion ternaria, estado = 0, sino estado = 1
        return true;
    }
    else
    {
        return false;
    }
}

void Motor::parada(){
    regimen=0;
    estado=0;
}