#include <iostream>

using namespace std;

void visualizar( int valores[], int nelementos)
{
    for( int indx = 0; indx < nelementos; indx++)
    {
        cout<<valores[indx]<< " ";
    }
    cout<<""<<endl;
}

int maximo( int valores[], int longitud )
{
    int maximo=0;
    for(int i=0; i<longitud; i++)
    {
        if (valores[i]>maximo)
        {
            maximo=valores[i];
        }
    }
    return maximo;
}

int minimo( int valores[], int longitud )
{
    int minimo;
    minimo=valores[0];
    for(int i=0; i<longitud; i++)
    {
        if (valores[i]<minimo)
        {
            minimo=valores[i];
        }
    }
    return minimo;
}

float media( int valores[], int longitud )
{
    float total=0;
    float media;
    int contador=0;
    for(int i=0; i<longitud; i++)
    {
        total=total+valores[i];
        contador++;
    }
    media=total/contador;
    return media;
}

void ordenar( int valores[], int longitud )
{
    for(int i=0; i<longitud; i++)
    {
        for(int j=i+1; j<longitud; j++)
        {
            if(valores[i]> valores[j])
            {
                int aux=valores[i];
                valores[i]=valores[j];
                valores[j]=aux;
            }
        }
        cout<<valores[i]<< " ";
    }
    cout<<""<<endl;
}

void invertir( int valores[], int longitud )
{
    int i=0;
    int aux;

        for(int i=0; i<longitud/2; i++)
        {
            aux=valores[i];
            valores[i]=valores[longitud-1-i];
            valores[longitud-1-i]=aux;
        }
        visualizar(valores, longitud);
}

int encontrar( int valores[], int buscado, int longitud )
{
    int encontrado;
    for(int i=0; i<longitud; i++)
    {
        if(valores[i]==buscado)
        {
            encontrado=valores[i];
        }
    }
    return encontrado;
}

int contar( int valores[], int buscado, int longitud )
{
    int contador=0;
    for(int i=0; i<longitud; i++)
    {
        if(valores[i]==buscado)
        {
            contador++;
        }
    }
    return contador;
}

int main()
{
    int valores[] { -9,20,8,3,5,99,3,35,101};
    int valores2[] { -9,20,8,3,5,99,3,35};
    visualizar(valores, 9);
    cout << maximo(valores, 9) << endl;
    cout << minimo(valores, 9) << endl;
    cout << media(valores, 8) << endl;
    ordenar(valores, 9);
    invertir(valores, 9);
    cout << encontrar(valores, 3, 9) << endl;
    cout << contar(valores, 3, 9) << endl;
    cout<<""<<endl;
    cout << maximo(valores2, 8) << endl;
    cout << minimo(valores2, 8) << endl;
    cout << media(valores2, 8) << endl;
    ordenar(valores2, 8);
    invertir(valores2, 8);
    cout << encontrar(valores2, 3, 8) << endl;
    cout << contar(valores2, 3, 8) << endl;

    return 0;
}
