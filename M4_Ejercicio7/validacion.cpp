#include "validacion.h"
#include <iostream>
#include <string.h>

using namespace std;

int obtenerOpcion()
{
    int opcion;
    while (!(cin >> opcion) || opcion < 1 || opcion > 3) //!(parametro true) = false, while=true para salir
    {
        cout << "Por favor, ingrese una opción válida (1-3): ";
        cin.clear();
        cin.ignore(10000, '\n'); // ignorar hasta 10000 caracteres o hasta encontrar un salto de línea, es para evitar que se quede en un bucle infinito
    }
    return opcion;
}

void obtenerMatricula(char *matricula)
{
    string entrada;

    do
    {
        cout << "Introduzca matricula (7 caracteres): ";
        cin >> entrada;
        cin.ignore(10000, '\n');
    } while (entrada.length() != 7);
    strcpy(matricula, entrada.c_str());
}

void obtenerTiempo(int &h, int &m, float &s)
{
    cout << "Introduzca horas: ";
    while (!(cin >> h))
    {
        cout << "Por favor, introduzca un número de horas válido: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Introduzca minutos: ";
    while (!(cin >> m))
    {
        cout << "Por favor, introduzca un número de minutos válido: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Introduzca segundos: ";
    while (!(cin >> s))
    {
        cout << "Por favor, introduzca un número de segundos válido: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
