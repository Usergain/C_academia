#include <iostream>

using namespace std;

int main()
{
    float distancia;
    float horas;
    float minutos;
    float segundos;
    float velocidad;

    cout << " Dame una distancia a calcular " << endl;
    cin >> distancia;
    cout << " Dame el tiempo que tarda en horas, minutos y segundo: " << endl;
    cin >> horas;
    cin >> minutos;
    cin >> segundos;
    horas += (minutos/60) + (segundos/3600);
    velocidad = distancia / horas ;
    cout << horas << endl;
    cout << " La velocidad media del trayecto es: " <<velocidad<< endl;

    return 0;
}
