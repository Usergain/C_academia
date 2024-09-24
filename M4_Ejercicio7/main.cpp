#include <iostream>
#include "carrera.h"
#include "tiempo.h"
#include "validacion.h"

using namespace std;

int main()
{
    Carrera carrera;
    while (true)
    {
        cout << "1.- Registrar Participante\n2.- Registra Tiempo\n3.- Mostrar Ganadores\nSeleccione una opción:" << endl;
        int opcion = obtenerOpcion();

        switch (opcion)
        {
        case 1:
        {
            char matricula[8];
            obtenerMatricula(matricula); 
            carrera.registrar_coche(matricula);
            break;
        }
        case 2:
        {
            char matricula[8];
            int h, m;
            float s;

            obtenerMatricula(matricula);
            obtenerTiempo(h, m, s);
            carrera.registrar_tiempo(matricula, Tiempo(h, m, s));
            break;
        }
        case 3:
        {
            cout << "Ganador: " << carrera.buscar_ganador() << endl;
            carrera.mostrar_partcipiantes();
            break;
        }
        default:
        cout << "Opción no válida." << endl;
        }
    }

    return 0;
}