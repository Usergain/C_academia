#include "hospital.h"
#include "habitacion.h"
#include <iostream>
#include <fstream>

int main()
{
    // Verificar si el archivo "ocupacion.txt" existe
    std::ifstream archivoExistente("ocupacion.txt");
    if (!archivoExistente)
    {
        std::ofstream nuevoArchivo("ocupacion.txt");
        if (!nuevoArchivo)
        {
            std::cout << "Error al crear el archivo 'ocupacion.txt'" << std::endl;
            return 1;
        }

        nuevoArchivo << "Ejemplo de linea en el archivo" << std::endl;
    }

    Hospital hospital;

    hospital.mostrarEstado();

    hospital.mostrarHabitaciones(); // Agregar esta línea

    // Generar números de historial para los pacientes y actualizar el estado del hospital
    hospital.actualizarEstado();

    int num_historial = 55555;
    hospital.costePaciente(num_historial);

    double coste_total = hospital.costeHospitalario();
    std::cout << "Coste total: " << coste_total << std::endl;

    hospital.buscarCamaLibre();

    return 0;
}
