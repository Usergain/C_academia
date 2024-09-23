/*Crea una aplicacion que rellene una matriz de 10 valores con valores enteros
comprendidos entre 50 y -50. Despues la aplicacion debe mostrar los valores
almacenados. Para generar numeros aleatorios emplea funcion rand() incluida en la
libreria stdlib.h ( cstdlib en C++ ). La funcion devuelve un numero aleatorios
comprendido entre 0 y la constante RAND_MAX.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void aleatorio(int valores[], int min, int max)
{
    for (int i = 0; i <= 10; i++)
    {
        valores[i] = min + rand() % (max - min + 1);
    }
}

int main()
{
    // Inicializar la semilla para los números aleatorios
    srand(time(nullptr));

    int min = -50;
    int max = 50;
    int valores[10];

    aleatorio(valores, min, max);

    cout << " Valores almacenados en la matriz:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << valores[i] << " ";
    }
    cout << endl;

    return 0;
}
