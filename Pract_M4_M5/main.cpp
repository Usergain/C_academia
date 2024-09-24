#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Habitacion {
    int num_habitacion;
    string tipo;
    vector<int> camas;
    double costo_dia;
};

vector<Habitacion> habitaciones = {
    {1, "IND", {0, -1}, 500},
    {2, "COM", {0, 0}, 250},
    {3, "COM", {0, 0}, 250},
    {5, "IND", {0, -1}, 500},
    {6, "COM", {0, 0}, 350}
};

void guardarOcupacion() {
    ofstream archivo("ocupacion.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo 'ocupacion.txt'" << endl;
        return;
    }

    archivo << "11111 2 2" << endl;
    archivo << "33333 1 1" << endl;
    archivo << "44444 4 1" << endl;
    archivo << "55555 1 2" << endl;
    archivo << "77777 5 1" << endl;
    archivo << "99999 10 2" << endl;

    archivo.close();
}

void mostrarEstado() {
    cout << "LISTADO DE HABITACIONES" << endl;
    for (const auto& habitacion : habitaciones) {
        cout << "N. habitacion: " << habitacion.num_habitacion;
        cout << " Tipo: " << habitacion.tipo;
        cout << " Cama-1: " << (habitacion.camas[0] != 0 ? "1" : to_string(habitacion.camas[0]));
        cout << " Cama-2: " << (habitacion.camas[1] != 0 ? "1" : to_string(habitacion.camas[1])) << endl;
    }
}

void actualizarEstado() {
    ifstream archivo("ocupacion.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo 'ocupacion.txt'" << endl;
        return;
    }

    int n_historial, n_habitacion, n_cama;
    while (archivo >> n_historial >> n_habitacion >> n_cama) {
        bool habitacion_existe = false;
        bool cama_valida = false;
        for (auto& habitacion : habitaciones) {
            if (habitacion.num_habitacion == n_habitacion) {
                habitacion_existe = true;
                if (n_cama == 1 && (habitacion.camas[0] == 0 || habitacion.camas[0] == -1)) {
                    if (habitacion.camas[0] == -1) {
                        cout << "Error, la cama 1 de la habitacion " << n_habitacion << " no existe" << endl;
                    } else {
                        habitacion.camas[0] = n_historial;
                    }
                    cama_valida = true;
                    break;
                } else if (n_cama == 2 && habitacion.tipo == "COM" && (habitacion.camas[1] == 0 || habitacion.camas[1] == -1)) {
                    if (habitacion.camas[1] == -1) {
                        cout << "Error, la cama 2 de la habitacion " << n_habitacion << " no existe" << endl;
                    } else {
                        habitacion.camas[1] = n_historial;
                    }
                    cama_valida = true;
                    break;
                } else {
                    cout << "Error, la cama " << n_cama << " de la habitacion " << n_habitacion << " esta ocupada o no existe" << endl;
                    cama_valida = true;
                    break;
                }
            }
        }
        if (!habitacion_existe) {
            cout << "Error, habitacion " << n_habitacion << " no existente" << endl;
        }
    }
    archivo.close();
}

void costePaciente(int n_historial) {
    bool paciente_encontrado = false;
    for (const auto& habitacion : habitaciones) {
        for (int i = 0; i < 2; i++) {
            if (habitacion.camas[i] == n_historial) {
                cout << "El coste/dia del paciente " << n_historial << " en la habitacion " << habitacion.num_habitacion;
                cout << " es de: " << habitacion.costo_dia << " euros" << endl;
                paciente_encontrado = true;
                break;
            }
        }
        if (paciente_encontrado) {
            break;
        }
    }
    if (!paciente_encontrado) {
        cout << "Paciente inexistente o no registrado." << endl;
    }
}

void costeHospitalario() {
    double costo_total = 0;
    for (const auto& habitacion : habitaciones) {
        int camas_ocupadas = 0;
        for (int cama : habitacion.camas) {
            if (cama != 0 && cama != -1) {
                camas_ocupadas++;
            }
        }
        costo_total += camas_ocupadas * habitacion.costo_dia;
    }
    cout << "Coste hospitalario total: " << costo_total << " euros" << endl;
}

void buscarCamaLibre() {
    for (const auto& habitacion : habitaciones) {
        for (int i = 0; i < 2; i++) {
            if (habitacion.camas[i] == 0) {
                cout << "Se encontró una cama libre en la habitacion " << habitacion.num_habitacion;
                cout << " y cama " << (i + 1) << endl;
                return;
            }
        }
    }
    cout << "No hay camas libres." << endl;
}

int main() {
    guardarOcupacion();
    actualizarEstado();
    mostrarEstado();
    
    int n_historial;
    cout << "Ingrese el numero de historial del paciente: ";
    cin >> n_historial;

    costePaciente(n_historial);
    costeHospitalario();
    buscarCamaLibre();

    return 0;
}
