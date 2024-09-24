#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int validarNum(char numero[])
{
    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            cout << "Ingresa solo numeros" << endl;

            return 0;
        }
    }
    return 1;
}

int main()
{
    int bus = 40;
    char ticket[2];
    int verifirNumero;
    int billetes;
    char respuesta;

    do
    {
        do
        {
            cout << " Cuantos billetes de autobus quieres reservar? Quedan " << bus << " billetes."  << endl;
            cin >> ticket ;
            verifirNumero = validarNum(ticket);
        }while(verifirNumero==0);

        billetes = atoi(ticket);
        cout << billetes << endl;

        if (billetes >5)
        {
            cout << "No se pueden reservar más de 5 asientos a la vez. " << endl;
        }
        else
        {
            if(bus < billetes) {
                // Si pide mas plazas de las que hay
                do {
                    cout << " No hay tantos asiento disponibles, solo quedan " << bus << " billetes " <<endl;
                    cout << "Las quieres ? S /N " << endl;
                    cin.ignore(100, '\0');
                }while(respuesta != 'N' && respuesta != 'n' && respuesta != 'S' && respuesta != 's');
                if (respuesta == 'S' || respuesta == 's')
                {
                    cout << "Ya has reservado las " << bus << " asientos. Muchas gracias." << endl;
                    bus = 0;
                }
            } else {
                // Si pide menos o igual que plazas que hay.
                cout << " plazas vendidas. "<<endl;
                bus -= billetes;
            }
        }
    }while(bus > 0 );
    cout << " Ya no quedan más billetes de bus, muchas gracias.";
    return 0;
}

    //getch

