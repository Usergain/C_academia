#include <iostream>

using namespace std;

int main()
{
    int num1;
    int num2;
    int num3;

    cout << " Vamos a jugar al juego de los tres numeros : " << endl;
    cout << " Dame el primer numero: " << endl;
    cin >> num1;
    cout << " Dame el segundo numero: " << endl;
    cin >> num2;
    cout << " Dame el tercer numero: " << endl;
    cin >> num3;

    if (num1 > num2 && num1 > num3)
    {
        cout << " El mayor numero es el: " << num1 << endl;
    }
    else if (num1 < num2 && num2 > num3)
    {
        cout << " El mayor numero es el: " << num2 << endl;
    }
    else if( num3 > num1 && num3 > num2 )
        cout << " El mayor numero es el: " << num3 << endl;

    return 0;
}
