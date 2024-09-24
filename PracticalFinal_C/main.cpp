#include "HabitacionesHospital.h"
#include <iostream>

using namespace std;

int main() {
    HabitacionesHospital hospital;
    hospital.guardarOcupacion();
    hospital.actualizarEstado();
    hospital.mostrarEstado();

    int n_historial;
    cout << "Ingrese el numero de historial del paciente: ";
    cin >> n_historial;

    hospital.costePaciente(n_historial);
    hospital.costeHopitalario();
    hospital.buscarCamaLibre();

    return 0;
}