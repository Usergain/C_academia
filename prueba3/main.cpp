#include <iostream>
using namespace std;
// Funcion de inicio
int main( int argc, const char* argv[] ){
// Comprueba que hay parámetros.
// El parámetro 0 siempre existe, y es el propio nombre del ejecutable.
if ( argc > 1 ) {
 // Bucle de obtencion de lista de parámetros
 cout<<"PARAMETERS LIST"<<endl;
 for( int i = 1; i < argc; i++ ){
 // Visualizacion de indice y parámetro
 cout<<i<<"-"<<argv[i]<<endl;
 }
 cout<<"END LIST"<<std::endl;
 } else {
 cout<<"NO PARAMETERS";
 }
return 0;
}
