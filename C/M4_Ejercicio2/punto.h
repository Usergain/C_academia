#ifndef PUNTO_h
#define PUNTO_H

#include <iostream>

class Punto{
private:
int x;
int y;

public:
Punto();
Punto(int x, int y);

int getX();
int getY();
void setX(int x);
void setY(int y);

void obtenerDescripcion();

};

#endif