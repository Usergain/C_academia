#include<iostream>

using namespace std;

int main()
{
    int horas;
    int precio;
    int salario=horas*precio;

    cout<<"Dame numero de horas trabajadas"<<endl;
    cin>>horas;
    cout<<"Precio por hora"<<endl;
    cin>>precio;
    cout<<"El salario semanal del trabajador es: "<<horas<<" + <<precio/h " precio " = "<<salario<<endl;

    return 0;
}
