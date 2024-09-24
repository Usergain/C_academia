#ifndef FIGURA_H
#define FIGURA_H

#include <string>

class Figura
{
protected:
    float CoordenadaX;
    float CoordenadaY;

public:
    Figura(float x, float y);

    // Métodos abastractos
    virtual std::string ObtenerDescripcion();
    virtual float ObtenerArea() = 0;
};

#endif