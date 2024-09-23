#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <vector>
#include <string>

class Habitacion; // Declaracion adelantada de la clase Habitacion

class Hospital
{
public:
    Hospital();

    void mostrarEstado();
    void actualizarEstado();
    void costePaciente(int num_historial);
    double costeHospitalario();
    void buscarCamaLibre();
    void guardarEstadoEnArchivo();
    void mostrarHabitaciones();

private:
    std::vector<Habitacion> habitaciones;
    std::vector<int> numerosHistorial;
    std::string obtenerTipoCama(int valor);
    Habitacion *buscarHabitacion(int num_historial);
};

#endif // HOSPITAL_H