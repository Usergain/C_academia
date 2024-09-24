#include <iostream>

using namespace std;

const float P_MANZANAS=2;
const float P_NARANJAS=2.25;
const float P_LIMONES=1.15;

short int fnt_election()
{
    short int option;
    do
    {
        cout << "1.- Manzanas" << endl;
        cout << "2.- Naranjas" << endl;
        cout << "3.- Limones" << endl;
        cout << "0.- Salir" << endl;
        cin >> option;
    }
    while(option!=0 && option!=1 && option!=2 && option!=3);
    return option;
}

int fnt_peso()
{
    float kg;
    do
    {
        cout << " Teclee la cantidad en kg. " << endl;
        cin >> kg;
        if(kg<0)
        {
            cout << " PESO NO VALIDO " <<endl;
        }
    }
    while(kg<0);
    return kg;
}

char fnt_pago ()
{
    char pago;
    do
    {
        cout << " Metodo de pago tajeta(t) o al contado(c)" << endl;
        cin >> pago;
        if(pago!=116 && pago!=84 && pago!=67 && pago!=99)
        {
            cout << "RESPUESTA INCORRECTA" << endl;
        }
    }
    while(pago!=116 && pago!=84 && pago!=67 && pago!=99);

    return pago;
}

float fnt_precio(const float PRECIOFRUTA,int kg, char formaPago)
{
    float precio;

//pago con tarjeta

    if(formaPago==116 || formaPago==84)
    {
        if(kg<3)
        {
            precio=(PRECIOFRUTA*kg);
        }
        else if(kg>=3 && kg<5)
        {
            precio=(PRECIOFRUTA*kg)*0.85;
        }
        else if((kg>=5 && kg<7))
        {
            precio=(PRECIOFRUTA*kg)*0.75;
        }
        else if((kg>=7 && kg<=10))
        {
            precio=(PRECIOFRUTA*kg)*0.70;
        }
        else
        {
            precio=(PRECIOFRUTA*kg)*0.60;
        }

    }

    //pago sin tarjeta

    else
    {
        if(kg<3)
        {
          precio=(PRECIOFRUTA*kg);
        }
        else if(kg>=3 && kg<5)
        {
            precio=(PRECIOFRUTA*kg)*0.90;
        }
        else if((kg>=5 && kg<7))
        {
            precio=(PRECIOFRUTA*kg)*0.80;
        }
        else if((kg>=7 && kg<=10))
        {
            precio=(PRECIOFRUTA*kg)*0.75;
        }
        else
        {
            precio=(PRECIOFRUTA*kg)*0.65;
        }
    }
    return precio;
}

    int main()
    {
        float kg;
        char pago;
        int option;

        option=fnt_election();

        if(option==1)
        {
            kg=fnt_peso();
            pago=fnt_pago();
            cout << "TOTAL: "<< fnt_precio(P_MANZANAS, kg, pago) << endl;
        }
        else if(option==2)
        {
            kg=fnt_peso();
            pago=fnt_pago();
            cout << "TOTAL: "<< fnt_precio(P_NARANJAS, kg, pago) << endl;
        }else if(option==3)
        {
            kg=fnt_peso();
            pago=fnt_pago();
            cout << "TOTAL: "<< fnt_precio(P_LIMONES, kg, pago) << endl;
        }else

        return 0;
    }
