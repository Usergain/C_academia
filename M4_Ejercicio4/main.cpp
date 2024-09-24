#include "cbancaria.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función de comparación para ordenar las cuentas por beneficios (de mayor a menor)
bool comparar_cuentas(const CBancaria &cuenta1, const CBancaria &cuenta2)
{
    return cuenta1.calcular_beneficio() > cuenta2.calcular_beneficio();
}

int main()
{

    vector<CBancaria> cuentas;

    // Pedir al usuario los datos de las cuentas
    for (int i = 0; i < 5; i++)
    {
        string titular;
        double saldo, interes;

        cout << "Ingrese el nombre del titular de la cuenta: " << i + 1 << ": ";
        cin >> titular;

        cout << "Ingrese el saldo de la cuenta: " << i + 1 << ": ";
        cin >> saldo;

        cout << "Ingrese el interes de la cuenta: " << i + 1 << ": ";
        cin >> interes;

        CBancaria cuenta(titular, saldo, interes);
        cuentas.push_back(cuenta); // Añadir la cuenta al vector
    }

    //ordenar las cuentas por beneficios (de mayor a menor)
    sort(cuentas.begin(), cuentas.end(), comparar_cuentas);

    // Mostrar cuenta ordenadas
    for (const CBancaria &cuenta : cuentas)
    {
        cuenta.visualizar();
        cout << "-------------------------------------------" << endl;
    }

    return 0;
}