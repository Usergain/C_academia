#include <iostream>

using namespace std;

int main()
{
   int i, j;

   // Para imprimir primera mitad de la piramide
   // las columnas
   for (i = 1; i < 8; ++i)
   {
      // las lineas
      for (j = 1; j < i; ++j)
      {
         cout << "$";
      }
      cout << "$"; // este es el ultimo y salto de linea
      cout << endl;
   }

   // Para imprimir segunda mitad de la piramideS
   for (i = 8; i >= 1; --i)
   {
      for (j = 1; j <= i; ++j)
      {
         cout << "$";
      }
      cout << endl;
   }
   return 0;
}
