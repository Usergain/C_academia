#include <iostream>

using namespace std;

void sumar(int numA, int numB){
    int resultado = numA + numB;
    cout << resultado << endl;
}

void sumar (int numA, int numB, int numC){
    int resultado = numA + numB + numC;
    cout << resultado << endl;
}

void sumar (double numA, double numB){
    double resultado = numA + numB;
    cout << resultado << endl;
}

int main()
{
    sumar(10, 20);
    sumar(100, 200, 300);
    sumar(10.7, 20.99);

    return 0;
}
