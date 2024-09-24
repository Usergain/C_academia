#include <iostream>

using namespace std;

int cociente(int dividendo, int divisor){
    int contador = 0;

    while(dividendo >= divisor){
        dividendo -= divisor;
        contador ++;
    }
    return contador;
}

int resto(int dividendo, int divisor){
    int resto = 0;
    while(dividendo >= divisor){
        dividendo -= divisor;
    }
    return dividendo;
}

int main()
{
    int dividendo;
    int divisor;
    int resultado;

    cout << "Dame un dividendo " << endl;
    cin >> dividendo;
    cout << "Dame un divisor " << endl;
    cin >> divisor;

    if(divisor !=0){
        cout << "El cociente de la division es: " << cociente(dividendo, divisor) << endl;
        cout << "El resto de la division es: " << resto(dividendo, divisor) << endl;
    }
    else
        cout << "El divisor no puede ser cero" << endl;
    return 0;
}
