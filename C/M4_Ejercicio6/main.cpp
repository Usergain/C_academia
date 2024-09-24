#include <iostream>
#include <vector>

#include "cuadrado.h"
#include "triangulo.h"
#include "circulo.h"


using namespace std;

int main()
{
    vector<Figura *> figuras;
    figuras.push_back(new Circulo(10, 10, 20));
    figuras.push_back(new Cuadrado(20, 20, 5));
    figuras.push_back(new Triangulo(30, 30, 5, 2));

    for (Figura *figura : figuras)
    {
        cout << figura->ObtenerDescripcion() << endl;
        cout << "Area: " << figura->ObtenerArea() << endl;
    }

    // Liberar memoria
    for (Figura *figura : figuras)
    {
        delete figura;
    }

    return 0;
}