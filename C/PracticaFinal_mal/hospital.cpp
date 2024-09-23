#include "hospital.h"
#include "habitacion.h"
#include <iostream>
#include <fstream>
#include <random>

Hospital::Hospital()
{
    habitaciones = {
        {1, "IND", {0, -1}, 500},
        {2, "COM", {0, 0}, 250},
        {3, "COM", {0, 0}, 250},
        {5, "IND", {0, -1}, 500},
        {6, "COM", {0, 0}, 350}};
}

void Hospital::mostrarEstado()
{

    // recorrer con iterador
    for (auto it = habitaciones.begin(); it != habitaciones.end(); ++it)
    {
        it->mostrarEstado();
    }
}

void Hospital::actualizarEstado()
{
    // Limpiar el vector de números de historial antes de actualizar el estado
    numerosHistorial.clear();

    std::ifstream archivo("ocupacion.txt");
    if (!archivo)
    {
        std::cout << "Error al abrir el archivo" << std::endl;
        return;
    }

    int num_habitacion, num_cama;

    while (archivo >> num_habitacion >> num_cama)
    {
        Habitacion *habitacion = buscarHabitacion(num_habitacion);

        if (habitacion == nullptr)
        {
            std::cout << "Error, habitacion " << num_habitacion << " no existe" << std::endl;
            continue;
        }

        if (num_cama < 1 || num_cama > 2)
        {
            std::cout << "Error, cama " << num_cama << " no existe" << std::endl;
            continue;
        }

        if (!habitacion->ocuparCama(num_cama))
        {
            std::cout << "Error, cama " << num_cama << " de la habitacion " << num_habitacion << " no esta disponible" << std::endl;
        }
        else
        {
            // Asignar pacientes específicos a las camas ocupadas
            switch (num_habitacion)
            {
                case 1:
                    numerosHistorial.push_back(55555);
                    break;
                case 2:
                    numerosHistorial.push_back(11111);
                    break;
                case 3:
                    numerosHistorial.push_back(33333);
                    break;
                case 4:
                    numerosHistorial.push_back(44444);
                    break;
                case 5:
                    numerosHistorial.push_back(77777);
                    break;
                case 6:
                    numerosHistorial.push_back(99999);
                    break;
                default:
                    // No hay paciente asignado para esta habitación, agregamos un número de historial inválido
                    numerosHistorial.push_back(-1);
                    break;
            }
        }
    }

    archivo.close();

    // Guardar el estado actualizado en el archivo
    guardarEstadoEnArchivo();
}

void Hospital::guardarEstadoEnArchivo()
{
    std::ofstream archivo("ocupacion.txt");
    if (!archivo)
    {
        std::cout << "Error al abrir el archivo 'ocupacion.txt'" << std::endl;
        return;
    }

    for (const auto &habitacion : habitaciones)
    {
        if (habitacion.camas[0] != 0)
        {
            archivo << habitacion.camas[0] << " " << habitacion.num_habitacion << " 1" << std::endl;
        }

        if (habitacion.camas[1] != 0)
        {
            archivo << habitacion.camas[1] << " " << habitacion.num_habitacion << " 2" << std::endl;
        }
    }

    archivo.close();
}

void Hospital::costePaciente(int num_historial)
{
    double coste_total = 0.0;
    bool encontrado = false;

    for (auto &habitacion : habitaciones)
    {
        if (habitacion.camas[0] == num_historial || habitacion.camas[1] == num_historial)
        {
            coste_total += habitacion.obtenerCoste();
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        std::cout << "Paciente inexistente." << std::endl;
    }
    else
    {
        std::cout << "El coste total del paciente es: " << coste_total << std::endl;
    }
}

double Hospital::costeHospitalario()
{
    double coste_total = 0.0;
    for (auto &habitacion : habitaciones)
    {
        coste_total += habitacion.obtenerCoste();
    }
    return coste_total;
}

void Hospital::buscarCamaLibre()
{
    for (auto &habitacion : habitaciones)
    {
        for (int i = 0; i < 2; i++)
        {
            if (habitacion.camas[i] == 0)
            {
                std::cout << "Se ha encontrado una cama libre en la habitacion " << habitacion.num_habitacion << ", cama " << i + 1 << std::endl;
                return;
            }
        }
    }
    std::cout << "No hay camas libres." << std::endl;
}

Habitacion *Hospital::buscarHabitacion(int num_habitacion)
{
    for (auto &habitacion : habitaciones)
    {
        if (habitacion.num_habitacion == num_habitacion)
            return &habitacion;
    }
    return nullptr;
}

void Hospital::mostrarHabitaciones()
{
    std::cout << "Habitaciones en el hospital:" << std::endl;
    for (const auto &habitacion : habitaciones)
    {
        std::cout << "Habitacion: " << habitacion.num_habitacion << ". Tipo: " << habitacion.tipo << ". Cama-1: " << habitacion.camas[0] << ". Cama-2: " << habitacion.camas[1] << std::endl;
    }
}
