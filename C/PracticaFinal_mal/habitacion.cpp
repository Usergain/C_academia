#include "habitacion.h"
#include <iostream>

void Habitacion :: mostrarEstado()
{
    std::cout << "Habitacion: " << num_habitacion << ". Tipo: " << tipo << ".Cama-1: " << camas[0] << ". Cama-2: " << camas[1] << std::endl;
}

bool Habitacion::ocuparCama(int num_cama)
{
    if (tipo == "IND")
    {
        std::cout << "Error, habitacion " << num_habitacion << "es individual" << std::endl;
        return false;
    }
    if (camas[num_cama - 1] == 0)
    {
        camas[num_cama - 1] = 1;
        return true;
    }
    else
    {
        std::cout << "Error, cama " << num_cama << " de la habitacion " << num_habitacion << " no esta disponible" << std::endl;
        return false;
    }
}

double Habitacion::obtenerCoste(){
    int camas_ocupadas = 0;
    for (int i = 0; i < 2; i++)
    {
        if (camas[i] == 1)
        {
            camas_ocupadas++;
        }
    }   
    return camas_ocupadas * costo_dia;
}
