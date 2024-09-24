#ifndef HABITACIONESHOSPITAL_H
#define HABITACIONESHOSPITAL_H

#include <vector>
#include <string>

class HabitacionesHospital
{
public:
    struct Habitacion
    {
        int num_habitacion;
        std::string tipo;
        std::vector<int> camas;
        double costo_dia;
    };

    HabitacionesHospital();

    void guardarOcupacion() const;
    void mostrarEstado() const;
    void actualizarEstado();
    void costePaciente(int n_historial) const;
    void costeHopitalario() const;
    void buscarCamaLibre() const;
    std::vector<Habitacion> habitaciones ;

};

#endif // HABITACIONESHOSPITAL_H