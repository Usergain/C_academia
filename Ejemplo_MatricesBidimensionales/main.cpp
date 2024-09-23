#include <iostream>

using namespace std;

int main()
{
    int valores[][5] =
    {
        { 1, 2, 3, 4, 5},
        { 6, 7, 8, 9,10},
        {11,12,13,14,15}
    };
// Recorrido de valores mostrando posiciones
    for( int fil = 0; fil <3; fil++)
    {
        for( int col = 0; col < 5; col++)
        {
            cout<<"["<<fil<<"]["<<col<<"] = "<<valores[fil][col]<<endl;
        }
    }
}
