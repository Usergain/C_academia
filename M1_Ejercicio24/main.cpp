#include <iostream>

using namespace std;

//Funcion que calcula el sumatorio de manera iterativa con un bucle for
int sumatorio(int valor){
    int suma = 0;
    int i;

    for(i=1; i<=valor; i++){

        suma = suma + i;
    }
    return suma;
}

//Funcion que calcula el sumatorio de manera recursiva
int sumatorio2(int valor){
    if ( valor > 1)
        return valor + sumatorio2(valor-1);
    else
        return 1;
}

// Función que calcula el sumatorio de manera recursiva usando el operador condicional ternario
int sumatorio3( int valor ) {
    return ( valor > 1) ? valor + sumatorio3(valor-1) : 1;
}

int main()
{
    int valor = 5;

    cout << "Sumatorio usando bucle for: " << sumatorio(valor) << endl;
    cout << "Sumatorio usando función recursiva: " << sumatorio2(valor) << endl;
    cout << "Sumatorio usando función recursiva (operador ternario): " << sumatorio3(valor) << endl;


    return 0;
}
