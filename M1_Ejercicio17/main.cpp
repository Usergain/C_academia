#include <iostream>

using namespace std;

int main()
{
    int bus = 40;
    int billetes;
    char respuesta;

    while (bus > 0)
    {
        cout << " Cuantos billetes de autobus quieres reservar? Quedan " << bus << " billetes." << endl;
        cin >> billetes;

        while (billetes > 5 || bus < billetes)
        {
            if (billetes > 5)
            {
                cout << "No se pueden reservar mas de 5 asientos a la vez. " << endl;
            }
            else if (bus < billetes)
            {
                cout << " No hay tantos asiento disponibles, solo quedan " << bus << " billetes " << endl;
                cout << "Las quieres ? S /N " << endl;
                cin >> respuesta;

                if (respuesta == 'S' || respuesta == 's')
                {
                    cout << " Gracias por su reserva, ya no hay mas billetes" << endl;
                    bus = 0;
                    break;
                }
                else if (respuesta == 'N' || respuesta == 'n')
                {
                    cout << "¿Desea reservar más billetes? S/N " << endl;
                    cin >> respuesta;

                    if (respuesta != 'S' && respuesta != 's')
                    {
                        break;
                    }
                }
            }

            cout << " Cuantos billetes de autobus quieres reservar? Quedan " << bus << " billetes." << endl;
            cin >> billetes;
        }

        if (billetes > 0)
        {
            bus -= billetes;
            cout << "Gracias por su reserva." << endl;
        }
    }
    cout << " Ya no quedan mas billetes de bus, muchas gracias.";
    return 0;
}
