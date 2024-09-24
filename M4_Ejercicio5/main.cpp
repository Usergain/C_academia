#include "vector2D.h"
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    vector<Vector2D> vectores;

    // Solicitar las coordenadas e identificadores de 4 posiciones
    for (int i = 0; i < 4; i++)
    {
        float x, y;
        string id;

        cout << "Ingrese las coordenada (x y) del vector " << i + 1 << ": ";
        cin >> x >> y;

        cout << "Ingrese el identificador del vector " << i + 1 << ": ";
        cin >> id;

        Vector2D vector(x, y, id);

        // Verififcar que no se introduzcan dos vectores iguales
        bool vectorRepetido = false;

        for (const Vector2D &v : vectores) //const Vector2D &v se utiliza para evitar copiar el vector
        {
            if (v == vector) // Se utiliza el operador == sobrecargado
            {
                vectorRepetido = true;
                break;
            }
        }

        if (vectorRepetido)
        {
            cout << "Error: El vector ya existe. Introduzca nuevamente los datos." << endl;
        }
        else
        {
            vectores.push_back(vector);
        }
    }

    // Solicitar el identificador de un vector
    string idBuscado;
    bool VectorEncontrado = false;
    Vector2D vectorEncontrar(0, 0, "");

    do
    {
        cout << "Ingrese el identificador de un vector: ";
        cin >> idBuscado;

        // Buscar el vector correspondiente al identificador dado
        for (const Vector2D &v : vectores)
        {
            if (v.getID() == idBuscado) 
            {
                v.mostrar();
                vectorEncontrar = v;
                VectorEncontrado = true;
                break;
            }
        }
        if (!VectorEncontrado)
        {
            cout << "Error: El identificador no se corresponde con ninguno de los vectore. Inténtelo nuevamente." << endl;
        }
    } while (!VectorEncontrado);

    // Buscar el el vector más cercano entre los almacenados
    float distanciaMinima = numeric_limits<float>::max(); // distanciaMinima se imicializa con el valor máximo de float
    const Vector2D* vectorCercano = nullptr; // Se utiliza un puntero para evitar copiar el vector

    for (const Vector2D &vector : vectores)
    {
        if (vector.getID() != idBuscado)
        {
            float distancia = Vector2D::obtenerDistancia(vectorEncontrar, vector); 
            if (distancia < distanciaMinima)
            {
                distanciaMinima = distancia;
                vectorCercano = &vector;
            }
        }
    }

    // Nostrar los datos del vector seleccionado y el vector más cercano
    cout << "\nDatos del vector seleccionado:" << endl;
    for (const Vector2D &vector : vectores)
    {
        if (vector.getID() == idBuscado)
        {
            vector.mostrar();
            break;
        }
    }

    if (vectorCercano != nullptr)
    {
        cout << "\nDatos del vectot más cercano:" << endl;
        vectorCercano->mostrar();
    }
    return 0;
}