#include "circulo.h"
#include <cmath>

Circulo::Circulo(float x, float y, float r) : Figura(x, y), radio(r) {}

std::string Circulo::ObtenerDescripcion()
{
    return "FIGURA CIRCULO: " + Figura::ObtenerDescripcion() + " Radio = " + std::to_string(radio);
}

float Circulo::ObtenerArea()
{
    return M_PI * radio * radio;
}