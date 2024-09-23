#include <iostream>

using namespace std;

int main()
{
    int numero;
    int resultado;
    int i;

    i=0;
    cout << "Dame un numero :" << endl;
    cin >> numero;
    while(i <=10)
    {
        resultado = numero * i;
        cout << numero << " x " << i << " = " << resultado << endl;
        i++;
    }
    return 0;
}
