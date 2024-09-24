#include "punto.h"

Punto::Punto()
{
    x = 0;
    y = 0;
}

Punto::Punto(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Punto::getX()
{
    return x;
}

int Punto::getY()
{
    return y;
}

void Punto::setX(int x)
{
    this->x = x;
}

void Punto::setY(int y)
{
    this->y = y;
}

void Punto::obtenerDescripcion()
{
    std::cout << "Coordenada X = " << x << " / Cooordenada Y = " << y << std::endl;
}