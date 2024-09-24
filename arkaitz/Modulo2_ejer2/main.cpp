#include <iostream>

using namespace std;

int main()
{
    int valor;
    char caracter;

    valor = 32;

    while(valor <= 126)
    {
        caracter = (char)valor;
        cout << "caracter-->" << caracter << endl;
        valor ++;
    }

    return 0;
}
