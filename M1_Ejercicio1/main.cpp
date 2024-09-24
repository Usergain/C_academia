#include<iostream>

using namespace std;

int main()
{
    int horas;
    float precio;
    float salario;

    cout<<"Dame numero de horas trabajadas"<<endl;
    cin>>horas;
    cout<<"Precio por hora"<<endl;
    cin>>precio;
    salario=horas*precio;
    cout<<"El salario semanal del trabajador es: "<<horas<<" horas trabajadas x " <<precio<< " precio/h  = "<<salario<<endl;
}
