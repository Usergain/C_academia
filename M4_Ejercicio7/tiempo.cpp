#include "tiempo.h"
#include <iostream>

using namespace std;

//Constructor
Tiempo::Tiempo(int _h, int _m, float _s) : h(_h), m(_m), s(_s){}

//Copy Constructor
Tiempo::Tiempo(const Tiempo& tiempo) : h(tiempo.h), m(tiempo.m), s(tiempo.s){}

//Metodo para obtener el tiempo total en segundos
float Tiempo::total() const{
    return h * 3600 + m *60 +s;
}

//Método para mostrar el tiempo
void Tiempo::mostrar() const{
    cout << "Tiempo: " << h << "; " << m << "; " << s << endl;
}

//Destructor
Tiempo::~Tiempo(){}