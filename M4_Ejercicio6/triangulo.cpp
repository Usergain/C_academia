#include "triangulo.h"

Triangulo::Triangulo(float x, float y, float b, float h) : Figura(x, y), base(b), altura(h) {}

std::string Triangulo::ObtenerDescripcion()
{
    return "FIGURA TRIANGULO: " + Figura::ObtenerDescripcion() + " BASE = " + std::to_string(base) + " ALTURA = " + std::to_string(altura);
}

float Triangulo::ObtenerArea()
{
    return (base * altura) / 2;
}