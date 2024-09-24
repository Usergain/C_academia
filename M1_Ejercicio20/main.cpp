#include <iostream>

using namespace std;

int potencia(int base, int exponente)
{
    int resultado = 1;

    for (int i = 0; i < exponente; i++)
    {
        resultado *= base;
    }

    return resultado;
}

int main(){
    int base;
    int exponente;

    cout << "Dame una base" << endl;
    cin >> base;
    cout << "Dame un exponente" << endl;
    cin >> exponente;
 
    cout << "El resultado de " << base << " elevado a " << exponente<< " es " << potencia(base, exponente) << endl; 

    return 0;
}