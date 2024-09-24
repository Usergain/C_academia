#include "cuadrado.h"

Cuadrado::Cuadrado(float x, float y, float l) : Figura(x, y), lado(l) {}

std::string Cuadrado::ObtenerDescripcion()
{
    return "FIGURA CUADRADO: " + Figura::ObtenerDescripcion() + " LADO = " + std::to_string(lado);
}

float Cuadrado::ObtenerArea()
{
    return lado * lado;
}