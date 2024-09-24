#include <iostream>
#include <cstdlib> //Necesario para rand()
#include <ctime>   //Necesario para time()

using namespace std;

int main()
{
    // Inicializando la semilla para generar números aleatorios
    srand(time(nullptr));

    int aleatorio = rand() % 21; // Generar un número aleatorio entre 0 y 20
    int num;
    int intentosFallidos = 0;
    int intentos = 0;

    cout << "Vamos a jugar al juego del acertijo numerico" << endl;

    // Solicitar al usuario que adivine el número
    while (true)
    {
        
        // aqui deberia ir el metodo que genera un numero aleatorio.
        cout << "Dame un numero" << endl;
        cin >> num;

        intentos++;

        if (num > aleatorio)
        {
            cout << "El numero introducido es mayor al numero generado." << endl;
        }
        else if (num < aleatorio)
        {
            cout << "El numero introducido es menor al numero generado." << endl;
        }
        else
        {
            cout << "Felicidades has adivinado el numero." << endl;
            break;
        }

        intentosFallidos++;
    }

    return 0;
}
