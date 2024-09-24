#ifndef CARRERA_H
#define CARRERA_H

#include "tiempo.h"
#include <string.h>

class Carrera
{
public:
    Carrera();
    virtual ~Carrera();
    void registrar_coche(const char *matricula);
    bool comprobar_coche(const char *matricula) const;
    bool registrar_tiempo(const char *matricula, const Tiempo &tiempo);
    const char *buscar_ganador() const;
    void mostrar_partcipiantes() const;

private:
    class Nodo
    {
    public:
        char matricula[7];
        Tiempo *tiempo;
        Nodo *siguiente;
        Nodo(const char *_matricula) //Constructor
        {
            strcpy(matricula, _matricula);
            tiempo = NULL;
            siguiente = NULL;
        }
        //Comprueba si la matricula es igual a la que se le pasa
        bool comprueba(const char *_matricula) const
        {
            return strcmp(matricula, _matricula) == 0;
        }
        virtual ~Nodo()
        {
            if (tiempo != NULL)
                delete tiempo;
        }
    };
    Nodo *buscar_coche(const char *matricula) const;
    Nodo *cabeza;
};

#endif /* CARRERA_H */