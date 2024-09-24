#include <iostream>

using namespace std;

void visualizar( int valores[], int nelementos)
{
    for( int indx = 0; indx < nelementos; indx++)
    {
        cout<<valores[indx]<<endl;
    }
}
void visualizar2( int *valores, int nelementos)
{
    for( int indx = 0; indx < nelementos; indx++)
    {
        cout<<valores[indx]<<endl;
    }
}

void limpiar( int m[], int longitud)
{
    for( int indx = 0; indx < longitud; indx++)
        m[indx] = 0;
}

int main()
{
    // Declaracion de matrices de 3 filas y 5 columnas.
    int valores[] = {1,2,3,4,5};
    visualizar( valores, 5);

    visualizar2( valores, 5);

    limpiar( valores, 5);
    visualizar( valores, 5);
    return 0;
}
