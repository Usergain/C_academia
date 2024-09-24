#include "figura.h"

Figura::Figura(float x, float y)  : CoordenadaX(x), CoordenadaY(y) {}

std::string Figura::ObtenerDescripcion()
{
    return "X= " + std::to_string(CoordenadaX) + "Y = " + std::to_string(CoordenadaY);
}