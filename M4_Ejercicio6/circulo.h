#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h"

class Circulo : public Figura
{
private:
    float radio;

public:
    Circulo(float x, float y, float r);

    std::string ObtenerDescripcion() override;
    float ObtenerArea() override;
};

#endif