#include <iostream>
using namespace std;
// Declaracion de una constante
#define DEBUG
// Funcion de inicio
int main() {
#ifdef DEBUG
// Este c�digo se compila y ejecuta si DEBUG est� definida
 cout<<"El codigo se ejecuta en modo depurado";
#else
// Este c�digo se compila y ejecuta si DEBUG no est� definida
 cout<<"El c�digo se ejecuta en modo normal";
#endif
return 0;
}
