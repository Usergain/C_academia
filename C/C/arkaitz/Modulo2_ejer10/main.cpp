#include <iostream>

using namespace std;

int main()
{
    int bus = 40;
    int billetes;
    while(bus > 0)
    {
        cout << " Cuantos billetes de autobus quieres reservar? Quedan " << bus << " billetes."  << endl;
        cin >> billetes ;

            while (billetes >6)
            {
                cout << "No se pueden reservar más de 5 asientos a la vez. " << endl;
                cout << " Cuantos billetes de autobus quieres reservar? " << endl;
                cin >> billetes ;
            }
        if(bus < billetes)
        {
            cout << " No hay tantos asiento disponibles, solo quedan " << bus << " billetes " <<endl;
            bus = 0;
        }
         bus -= billetes;
    }
    cout << " Ya no quedan más billetes de bus, muchas gracias.";
    return 0;
}
