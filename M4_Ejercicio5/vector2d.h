#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <string>

class Vector2D
{
private:
    float x;
    float y;
    std::string id;

public:
    Vector2D(float x, float y, const std::string &id);

    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
    std::string getID() const;

    void mostrar() const;

    bool operator==(const Vector2D &otro) const;
    Vector2D operator+(const Vector2D &otro) const;
    Vector2D operator-(const Vector2D &otro) const;

    float obtenerModulo() const;
    static float obtenerDistancia(const Vector2D &v1, const Vector2D &v2);
};

#endif