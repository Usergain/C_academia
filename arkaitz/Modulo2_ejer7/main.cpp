#include <iostream>

using namespace std;

int main()
{
   int i, j;

   for (i = 1; i < 8; ++i) { //las columnas
      for (j = 1; j < i; ++j) { //las lineas
         cout <<"$";
      }
      cout <<"$"; //este es el ultimo y salto de linea
      cout << endl;
   }
    for (i = 8; i >= 1; --i) {
      for (j = 1; j <= i; ++j) {
         cout << "$";
      }
      cout << endl;
   }
   return 0;
}
