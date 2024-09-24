#include "carrera.h"
#include <iostream>
#include <cstring>

using namespace std;

Carrera::Carrera() : cabeza(NULL) {}

Carrera::~Carrera()
{
    while (cabeza)
    {
        Nodo *temp = cabeza;        //
        cabeza = cabeza->siguiente; // avanza al siguiente nodo
        delete temp;                // borra el nodo
    }
}

// Registra un coche en la carrera
void Carrera::registrar_coche(const char *matricula)
{
    if (comprobar_coche(matricula))
    {
        cout << "Error: matricula ya registrada" << std::endl;
        return;
    }

    Nodo *nuevo = new Nodo(matricula);
    nuevo->siguiente = cabeza; // lo vincula al frente de la lista
    cabeza = nuevo;            // actualizamos la cabeza para que apunte al nuevo nodo
}

// Comprueba si el coche está registrado
bool Carrera::comprobar_coche(const char *matricula) const
{
    char matricula_min[8];
    strcpy(matricula_min, matricula); 

    Nodo *temp = cabeza; // apunta al frente de la lista
    while (temp)
    {
        char matricula_temp[8];
        strcpy(matricula_temp, temp->matricula);

        if (strcmp(matricula_temp, matricula_min) == 0) 
            return true;
        temp = temp->siguiente; // avanza al siguiente nodo
    }
    return false;
}

// Registra el tiempo de llegada del coche
bool Carrera::registrar_tiempo(const char *matricula, const Tiempo &tiempo)
{
    Nodo *coche = buscar_coche(matricula);
    if (coche == NULL)
    {
        cout << "Error: matricula no registrada" << endl;
        return false;
    }
    if (coche->tiempo != NULL)
    {
        cout << "Error: tiempo ya registrado" << endl;
        return false;
    }

    coche->tiempo = new Tiempo(tiempo);
    return true;
}

// Busca el ganador de la carrera
const char *Carrera::buscar_ganador() const
{
    if (cabeza == NULL)
        return "SIN PARTICIPANTES";

    Nodo *coche = cabeza;
    Nodo *ganador = NULL;
    while (coche)
    {
        // si el coche no tiene tiempo o el tiempo es menor que el del ganador
        if (coche->tiempo != NULL && (ganador == NULL || coche->tiempo != NULL && coche->tiempo->total() < ganador->tiempo->total()))
        {
            ganador = coche;
        }
        coche = coche->siguiente; // avanza al siguiente nodo
    }
    if (ganador == NULL || ganador->tiempo == NULL)
        return "SIN GANADOR";
    return ganador->matricula;
}

// Muestra los participantes de la carrera
void Carrera::mostrar_partcipiantes() const
{
    Nodo *coche = cabeza;
    while (coche)
    {
        cout << coche->matricula;
        if (coche->tiempo != NULL)
            coche->tiempo->mostrar();
        else
            cout << " LLEGADA NO REGISTRADA" << endl;
        coche = coche->siguiente;
    }
}

// Busca un coche en la carrera, accedemos al nodo y asi podemos acceder a su tiempo, etc..
Carrera::Nodo *Carrera::buscar_coche(const char *matricula) const // por que es una clase anidada
{
    Nodo *coche = cabeza;
    while (coche)
    {
        if (coche->comprueba(matricula))
            return coche;
        coche = coche->siguiente;
    }
    return NULL;
}
