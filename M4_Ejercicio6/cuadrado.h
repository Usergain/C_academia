#ifndef CUADRADO_H
#define CUADRADO_H

#include "figura.h"

class Cuadrado : public Figura
{
private:
    float lado;

public:
    Cuadrado(float x, float y, float l);

    std::string ObtenerDescripcion() override;
    float ObtenerArea() override;
};

#endif