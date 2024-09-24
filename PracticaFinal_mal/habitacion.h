#ifndef HABITACION_H
#define Habitacion_H

#include <string>

class Habitacion
{
public:
    int num_habitacion;
    std::string tipo;
    int camas[2];
    double costo_dia;

    void mostrarEstado();
    bool ocuparCama(int num_cama);
    double obtenerCoste();
};
#endif // HABITACION_H