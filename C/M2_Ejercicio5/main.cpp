#include <iostream>

/*4.- Crea una aplicacion que reciba un valor entero representando una cantidad
monetaria entera. La aplicacion debe entonces desglosar la cantidad en unidades de
moneda de los siguientes valores: 500,200,100,50,20,10,5,2,1.
Estos valores deben estar almacenados en una matriz monedas. La cantidad de cada
moneda debe almacenarse en una matriz cantidades en la posicion correspondiente a
la moneda en la matriz monedas. La aplicacion mostrara finalmente las cantidades
indicando moneda y cantidad:*/

//ENTERO(A4*100/(B4*100))--> resto

using namespace std;

void cuenta(int ingreso, int cantidades[8])
{
    int cantidad=0;
    while(ingreso>0)
    {
        if(ingreso>=500)
        {
            cantidades[0]=ingreso/500;
            ingreso=ingreso%500; //El resto
            cout<<ingreso<<endl;
        }
        else if(ingreso>=200)
        {
            cantidades[1]=ingreso/200;
            ingreso=ingreso%200;
            cout<<ingreso<<endl;
        }
        else if(ingreso>=100)
        {
            cantidades[2]=ingreso/100;
            ingreso=ingreso%100;
            cout<<ingreso<<endl;
        }
        else if(ingreso>=50)
        {
            cantidades[3]=ingreso/50;
            ingreso=ingreso%50;
            cout<<ingreso<<endl;
        }
        else if(ingreso>=20)
        {
            cantidades[3]=ingreso/20;
            ingreso=ingreso%20;
            cout<<ingreso<<endl;
        }
        else if(ingreso>=10)
        {
            cantidades[4]=ingreso/10;
            ingreso=ingreso%10;
            cout<<ingreso<<endl;
        }
        else if(ingreso>=5)
        {
            cantidades[5]=ingreso/5;
            ingreso=ingreso%5;
            cout<<ingreso<<endl;
        }

        else if(ingreso>=2)
        {
            cantidades[6]=ingreso/2;
            ingreso=ingreso%2;
            cout<<ingreso<<endl;
        }
        else if(ingreso==1)
        {
            cantidades[7]=ingreso;
            ingreso=0;
            cout<<ingreso<<endl;

        }

    }

    for( int i = 0; i < 8; i++)
    {
        cout<<cantidades[i]<< " ";
    }
    cout<<""<<endl;

}

int main()
{
    int cantidades[]={0,0,0,0,0,0,0,0};
    int ingreso;

    cout << "--------------------------- CAJERO AUTOMATICO -------------------------------"<<endl;
    cout << " Bienvenido a tu banco BANCO DIGITAL" <<endl;
    cout << "¿Cual es el importe que vas a ingresar?"<<endl;
    cin >> ingreso;

    cuenta(ingreso,cantidades);

    return 0;
}
