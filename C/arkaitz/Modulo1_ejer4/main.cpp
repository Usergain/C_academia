#include <iostream>

using namespace std;

int main()
{
    int segundos;
    int horas;
    int minutos;
    int seg;

    cout << "Indica numero de segundos: " << endl;
    cin >> segundos;
    horas = segundos /3600;
    minutos = (segundos / 60) - 60 ;
    seg = segundos /3600;

    cout << horas << " h " << minutos << " min " << seg << " seg " << endl;

    return 0;
}
