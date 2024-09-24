#include <iostream>
using namespace std;
// Declaracion de una constante
#define DEBUG
// Funcion de inicio
int main() {
#ifdef DEBUG
// Este código se compila y ejecuta si DEBUG está definida
 cout<<"El codigo se ejecuta en modo depurado";
#else
// Este código se compila y ejecuta si DEBUG no está definida
 cout<<"El código se ejecuta en modo normal";
#endif
return 0;
}
