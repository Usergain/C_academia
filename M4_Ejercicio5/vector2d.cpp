#include "vector2d.h"
#include <iostream>
#include <cmath>

using namespace std;

Vector2D::Vector2D(float x, float y, const std::string &id)
{
    this->x = x;
    this->y = y;
    this->id = id;
}

float Vector2D::getX() const
{
    return x;
}

float Vector2D::getY() const
{
    return y;
}

void Vector2D::setX(float x)
{
    this->x = x;
}

void Vector2D::setY(float y)
{
    this->y = y;
}

std::string Vector2D::getID() const
{
    return id;
}

void Vector2D::mostrar() const
{
    std::cout << "Vector " << id << ": (" << x << ", " << y << ")" << std::endl;
}

bool Vector2D::operator==(const Vector2D &otro) const
{
    return (x == otro.x) && (y == otro.y);
}

Vector2D Vector2D::operator+(const Vector2D &otro) const
{
    return Vector2D(x + otro.x, y + otro.y, "Suma");
}

Vector2D Vector2D::operator-(const Vector2D &otro) const
{
    return Vector2D(x - otro.x, y - otro.y, "Suma");
}

float Vector2D::obtenerModulo() const{
    return std::sqrt(x*x + y*y);
}

float Vector2D::obtenerDistancia(const Vector2D &v1, const Vector2D &v2){
    Vector2D diferencia = v1 - v2;
    return diferencia.obtenerModulo();
}