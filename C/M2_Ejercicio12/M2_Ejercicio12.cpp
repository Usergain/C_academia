#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Persona
{
    char nombre[10];
    char apellido[10];
    int edad;
};

struct CuentaBancaria
{
    int ncuenta;
    Persona *titular;
    double saldo;
    double interes;
};

CuentaBancaria *cuentas[10];
int numCuentas = 0;

int menu()
{
    int opcion;
    do
    {
        cout << "********************** MENU *************************" << endl;
        cout << "Seleccione una opcion:\n";
        cout << "0.- Salir\n";
        cout << "1.- Alta cliente nuevo\n";
        cout << "2.- Mostrar datos de cliente registrado\n";
        cout << "3.- Ingresar dinero en la cuenta registrada\n";
        cout << "4.- Reintegro dinero de cuenta registrada\n";
        cout << "5.- Listar cuentas registradas\n";
        cout << "6.- Mostrar capitales de las cuentas registradas\n";
        cout << "7.- Mostrar rendimiento de las cuentas registradas\n";
        cout << "8.- Eliminar una cuenta\n";
        cout << "*****************************************************" << endl;
        cin >> opcion;
        if (opcion < 0 || opcion > 8)
        {
            cout << "Opcion inexistente";
        }
    } while (opcion < 0 || opcion > 8);
    return opcion;
}

// **************FUNCIONES PARA VALIDAR NUMEROS ENTEROS: ***************************

int es_entero(char *entrada)
{
    int i = 0;

    if (entrada[0] == '-' || entrada[0] == '+')
    {
        i = 1; // Para omitir si es positivo o negativo, salta la primera posicion
    }

    while (entrada[i] != '\0')
    {
        if (entrada[i] < '0' || entrada[i] > '9')
        {
            return 0;
        }
        i++;
    }

    return 1;
}

// *******************FUNCIONES PARA VALIDAR LETRAS: ********************************

int son_letras(char *entrada)
{
    int i = 0;

    while (entrada[i] != '\0')
    {
        if (!((entrada[i] >= 'a' && entrada[i] <= 'z') || (entrada[i] >= 'A' && entrada[i] <= 'Z')))
        {
            return 0;
        }
        i++;
    }

    return 1;
}

// *******************FUNCIONES PARA VALIDAR DECIMALES: **********************************

double esDouble(char *entrada)
{
    char *resto;
    double valor = strtod(entrada, &resto);
    if (isspace(*resto) || *resto == '\0')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// *******************FUNCION ALTA DE CLIENTES NUEVOS: ********************************

void altaCliente()
{
    Persona *nuevoTitular = new Persona;
    CuentaBancaria *nuevaCuenta = new CuentaBancaria;
    char auxTeclado[10];
    double resultado; // Para realizar la verificacion de digitales

    if (numCuentas >= 10)
    {
        cout << "MEMORIA LLENA\n";
        return;
    }

    // Pedimos el numero de cuenta y verificamos:
    do
    {

        cout << "Num.Cuenta: " << endl;
        cin >> auxTeclado;
        if (es_entero(auxTeclado))
        {
            nuevaCuenta->ncuenta = atoi(auxTeclado);
            cout << "Num.Cuenta introducido correctamente." << endl;
        }
        else
        {
            cout << "El numero de cuenta no es correcto vuelva a introducirlo" << endl;
        }

    }

    while (!es_entero(auxTeclado));

    // Pedimos el nombre y verificamos:
    do
    {

        cout << "Nombre: " << endl;
        cin >> auxTeclado;
        if (son_letras(auxTeclado))
        {
            strcpy(nuevoTitular->nombre, auxTeclado);
            cout << "Nombre introducido correctamente." << endl;
        }
        else
        {
            cout << "El nombre no es correcto vuelva a introducirlo" << endl;
        }

    } while (!son_letras(auxTeclado));

    // Pedimos el apellido y verificamos:
    do
    {

        cout << "Apellido: " << endl;
        cin >> auxTeclado;
        if (son_letras(auxTeclado))
        {
            strcpy(nuevoTitular->apellido, auxTeclado);
            cout << "Apellido introducido correctamente." << endl;
        }
        else
        {
            cout << "El Apellido no es correcto vuelva a introducirlo" << endl;
        }

    } while (!son_letras(auxTeclado));

    // Pedimos la edad y verificamos:
    do
    {

        cout << "Edad: " << endl;
        cin >> auxTeclado;
        if (es_entero(auxTeclado))
        {
            nuevoTitular->edad = atoi(auxTeclado);
            cout << "Edad introducido correctamente." << endl;
        }
        else
        {
            cout << "La edad no es correcto vuelva a introducirlo" << endl;
        }

    } while (!es_entero(auxTeclado));

    // Pedimos el saldo y verificamos:

    do
    {

        cout << "El cliente cuanto saldo quiere ingresar?" << endl;
        cin >> auxTeclado;
        resultado = esDouble(auxTeclado);
        if (resultado != 1)
        {
            nuevaCuenta->saldo = atof(auxTeclado);
            cout << "El saldo introducido correctamente." << endl;
        }
        else
        {
            cout << "El saldo introducido no es correcto vuelva a introducirlo" << endl;
        }

    }

    while (resultado == 1);

    // Pedimos el tipo de interes y verificamos:
    do
    {

        cout << "Que tipo de interes se le va a aplicar al cliente?" << endl;
        cin >> auxTeclado;
        resultado = esDouble(auxTeclado);
        if (resultado != 1)
        {
            nuevaCuenta->interes = atof(auxTeclado);
            cout << "El interes introducido correctamente." << endl;
        }
        else
        {
            cout << "El interes introducido no es correcto vuelva a introducirlo" << endl;
        }

    }

    while (resultado == 1);

    nuevaCuenta->titular = nuevoTitular;
    cuentas[numCuentas] = nuevaCuenta;
    numCuentas++;
    cout << "Cliente registrado con exito\n";
}

void mostrarCliente()
{
    int numCuenta;
    cout << "Numero de cuenta:";
    cin >> numCuenta;
    for (int i = 0; i < numCuentas; i++)
    {
        if (cuentas[i]->ncuenta == numCuenta)
        {
            cout << "Titular: " << cuentas[i]->titular->nombre << " " << cuentas[i]->titular->apellido << " ," << cuentas[i]->titular->edad << " años." << endl;
            cout << "Saldo: " << cuentas[i]->saldo << endl;
            cout << "Intereses: " << cuentas[i]->interes << endl;
            return;
        }
    }
    cout << "CUENTA INEXISTENTE\n";
}

void ingreso()
{
    char auxTeclado[10];
    int numCuenta;
    double cantidad;

    do
    {

        cout << "Numero de cuenta del cliente: ";
        cin >> auxTeclado;
        if (es_entero(auxTeclado))
        {
            numCuenta = atoi(auxTeclado);
            do
            {
                cout << "Cantidad a ingresar: ";
                cin >> auxTeclado;
                cantidad = esDouble(auxTeclado);
                if (cantidad != 1)
                {
                    for (int i = 0; i < numCuentas; i++)
                    {
                        if (cuentas[i]->ncuenta == numCuenta)
                        {
                            if (cantidad < 0)
                            {
                                cout << "CANTIDAD NO PERMITIDA\n";
                            }
                            else
                            {
                                cuentas[i]->saldo += atof(auxTeclado);
                                cout << "El saldo introducido correctamente." << endl;
                                cout << "El nuevo del cliente " << cuentas[i]->ncuenta << " es :" << cuentas[i]->saldo << endl;
                                return;
                            }
                        }

                        cout << "CUENTA INEXISTENTE\n";
                    }
                }
                else
                {
                    cout << "El saldo introducido no es correcto vuelva a introducirlo" << endl;
                }

            }

            while (cantidad == 1);
        }
        else
        {
            cout << "El numero de cuenta no es correcto vuelva a introducirlo" << endl;
        }

    }

    while (!es_entero(auxTeclado));
}

void reintegro()
{
    char auxTeclado[10];
    int numCuenta;
    double cantidad;

    do
    {

        cout << "Numero de cuenta del cliente: ";
        cin >> auxTeclado;

        if (es_entero(auxTeclado))
        {
            numCuenta = atoi(auxTeclado);
            do
            {
                cout << "Cantidad a retirar: ";
                cin >> auxTeclado;

                cantidad = atof(auxTeclado);
  
                if (cantidad != 1)
                {
                    for (int i = 0; i < numCuentas; i++)
                    {
                        if (cuentas[i]->ncuenta == numCuenta)
                        {
                            if (cantidad < 0)
                            {
                                cout << "CANTIDAD NO PERMITIDA\n";
                            }
                            else if (cantidad > cuentas[i]->saldo)
                            {
                                cout << "Saldo insuficiente. El saldo actual es: " << cuentas[i]->saldo << endl;
                            }
                            else
                            {
                                cuentas[i]->saldo -= atof(auxTeclado);
                                cout << "El saldo introducido correctamente." << endl;
                                cout << "El nuevo del cliente " << cuentas[i]->ncuenta << " es :" << cuentas[i]->saldo << endl;
                                return;
                            }
                        }
                    }
                    cout << "CUENTA INEXISTENTE\n";
                }
                else
                {
                    cout << "El saldo introducido no es correcto vuelva a introducirlo" << endl;
                }

            }

            while (cantidad == 1);
        }
        else
        {
            cout << "El numero de cuenta no es correcto vuelva a introducirlo" << endl;
        }

    }

    while (!es_entero(auxTeclado));
}

void mostrarListado()
{
    for (int i = 0; i < numCuentas; i++)
    {
        if (cuentas[i] != NULL)
        {
            cout << "Cuenta: " << cuentas[i]->ncuenta << endl;
            cout << "Titular: " << cuentas[i]->titular->nombre << " " << cuentas[i]->titular->apellido << " ," << cuentas[i]->titular->edad << " años." << endl;
            cout << "Saldo: " << cuentas[i]->saldo << endl;
            cout << "Intereses: " << cuentas[i]->interes << endl;
        }
    }
}

void mostrarCapital()
{
    double total_capital = 0;
    for (int i = 0; i < numCuentas; i++)
    {
        double capital = cuentas[i]->saldo;
        cout << "Cuenta: " << cuentas[i]->ncuenta << "- Capital: " << capital << endl;
        total_capital += capital;
    }
    cout << "Capital total: " << total_capital << endl;
}

void mostrarInteres()
{
    double total_interes = 0;
    for (int i = 0; i < numCuentas; i++)
    {
        double interes = cuentas[i]->interes;
        cout << "Cuenta: " << cuentas[i]->ncuenta << "- Interes: " << interes << endl;
        total_interes += interes;
    }
    cout << "Interes total: " << total_interes << endl;
}

void eliminarCuenta()
{
    int numCuenta;

    cout << "Introduce el numero de cuenta a eliminar.\n";
    cin >> numCuenta;
    for (int i = 0; i < numCuentas; i++)
    {
        if (cuentas[i] != NULL && cuentas[i]->ncuenta == numCuenta)
        {
            delete cuentas[i];
            cuentas[i] = NULL;
            cout << "Cuenta eliminada con exito.\n";
            return;
        }
    }

    cout << "La cuenta no existe.\n";
}

int main()
{

    int opcion;

    do
    {

        opcion = menu();

        switch (opcion)
        {
        case 0:
            cout << " Adios, esperamos verte pronto" << endl;
            break;
        case 1:
            cout << " 1.- Alta nueva: " << endl;
            altaCliente();
            break;
        case 2:
            cout << " 2.- Mostrar datos: " << endl;
            mostrarCliente();
            break;
        case 3:
            cout << "3.- Ingresar: " << endl;
            ingreso();
            break;
        case 4:
            cout << "4.- Reintegro: " << endl;
            reintegro();
            break;
        case 5:
            cout << "5.- Listar clientes: " << endl;
            mostrarListado();
            break;
        case 6:
            cout << "6.- Listar saldos: " << endl;
            mostrarCapital();
            break;
        case 7:
            cout << "7.- Rendimientos cuenta clientes: " << endl;
            mostrarInteres();
            break;

        case 8:
            cout << "8.- Eliminar cuenta cliente" << endl;
            eliminarCuenta();
            break;

        default:
            cout << " Has introducido una opcion incorrecta, vuelve a intentarlo " << endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}
