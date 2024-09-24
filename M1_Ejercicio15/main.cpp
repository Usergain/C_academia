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
        if(bus < billetes)
        {
            cout << " Has superado el numero de billetes que se pueden reservar, solo puedes reservar " << bus << " billetes " <<endl;
            bus = 0;
        }
         bus -= billetes;
    }
    cout << " Ya no quedan mas billetes de bus, muchas gracias.";
    return 0;
}
