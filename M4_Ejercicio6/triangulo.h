#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "figura.h"

class Triangulo : public Figura
{
private:
    float base;
    float altura;

public:
    Triangulo(float x, float y, float b, float h);

    std::string ObtenerDescripcion() override;
    float ObtenerArea() override;
};

#endif