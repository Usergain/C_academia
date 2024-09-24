#include <iostream>

using namespace std;

int main()
{
    float num1;
    float num2;
    float resultado;

    cout << "Dame un primer numero: " << endl;
    cin >> num1;
    cout << "Dame un segundo numero: " << endl;
    cin >> num2;
    resultado = num1 + num2;
    cout << " El resultado de la suma es : " << resultado << endl;
    resultado = num1 - num2;
    cout << " El resultado de la resta es : " << resultado << endl;
    resultado = num1 * num2;
    cout << " El resultado de la multiplicacion es : " << resultado << endl;
    resultado = num1 / num2;
    cout << " El resultado de la division es : " << resultado << endl;

    return 0;
}
