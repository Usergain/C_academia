#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int matriz[13][13];
    //Relleno de elementos, multiplos:
    for(int i=0; i<=12; i++)
    {
        for(int j=0 ; j<=12; j++)
        {
            matriz[i][j] = i * j;
        }
    }
    //Dibujar cabecera de fila y la columna:
    cout<<setw(4);
    cout<<"X"<<setw(4);
    for(int x=0; x <=12; x++)
        cout<<x<<setw(4);
    cout<<endl;

    //Dibujar los elementos multiplos:
    for(int i=0; i<=12; i++)
    {
        cout<<i<<setw(4);
        for(int j=0 ; j<=12; j++)
        {
            cout <<matriz[i][j]<<setw(4);
        }
        cout<<endl;
    }

    return 0;
}

