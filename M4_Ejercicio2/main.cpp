#include <iostream>
#include "punto.h"

using namespace std; 

int main(){

    Punto punto1;
    punto1.obtenerDescripcion();

    Punto punto2(3, 5);
    punto2.obtenerDescripcion();

    punto2.setX(8);
    punto2.setY(-2);

    cout << "Coordenada X = " << punto2.getX() << " / Coordenada Y = " << punto2.getY() << endl;

    return 0;
}