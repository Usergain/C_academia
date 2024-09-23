#include <iostream>

using namespace std;

int potencia(int base, int exponente){
    int resultado=1;

    if(exponente==0){
       return 1;
    }
    else if(exponente==1){
        return base;
    }
    else
        return base*potencia(base,exponente-1);
}

int main()
{
    int base;
    int exponente;
    int resultado;

    cout << "Dame un numero" << endl;
    cin >> base;
    cout << "Dame un numero" << endl;
    cin >> exponente;

    resultado = potencia(base,exponente);

    cout << "El resultado es: " << resultado << endl;

    return 0;
}
