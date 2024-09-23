/************************************************************************************************************
Clase Aritmetica
Crear una clase Aritmetica que permita realizar cálculos matemáticos. La clase debe
tener dos atributos privados de tipo entero y cumplir los siguientes requisitos:
 - Un constructor que reciba dos parámetros enteros, y métodos para obtener y modificar el valor
de sus atributos.
 - Cuatro métodos públicos: sumar(), restar(), producto() y división(); que devolverán en cada caso
el resultado correspondiente con el tipo adecuado.
Realizar una pequeña aplicación de que instancie un objeto de la clase CAritmetica con
un par de valores dados por el usuario y que muestre a continuación su suma, resta,
producto y división empleando sus métodos miembros.
************************************************************************************************************/

#include <iostream>
#include "aritmetica.h"

using namespace std;

int main()
{
    int num1, num2;

    cout << "Ingrese el primer número: ";
    cin >> num1;

    cout << "Ingrese el segundo número: ";
    cin >> num2;

    Aritmetica calculadora(num1, num2);

    cout << "Suma: " << calculadora.sumar() << endl;
    cout << "Resta: " << calculadora.restar() << endl;
    cout << "Multiplicación: " << calculadora.producto() << endl;
    cout << "División: " << calculadora.division() << endl;

    return 0;
}