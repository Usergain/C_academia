#include <iostream>
#include "motor.h"

using namespace std;

int main(){

    Motor motor1;
    cout << "Estado: " << (motor1.getEstado() == 0 ? "Parado" : "Marcha") << endl;
    cout << "regimen: " << motor1.getRegimen() << endl;

    Motor motor2(2);
    cout << "Estado: " << (motor2.getEstado() == 0 ? "Parado" : "Marcha") << endl;
    cout << "regimen: " << motor2.getRegimen() << endl;

    motor2.aumentarRegimen();
    cout << "regimen: " << motor2.getRegimen() << endl;

    motor2.reducirRegimen();
    cout << "regimen: " << motor2.getRegimen() << endl;

    motor2.parada();
    cout << "Estado: " << (motor2.getEstado() == 0 ? "Parado" : "Marcha") << endl;
    cout << "regimen: " << motor2.getRegimen() << endl;

    return 0;
}