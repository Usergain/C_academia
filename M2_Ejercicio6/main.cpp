#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

void visualizar( char diccionario[], int nelementos)
{
    cout<<"[ ";
    for( int indx = 0; indx < nelementos; indx++)
    {
        cout<< diccionario[indx];
    }
    cout<<" ]";
    cout<<""<<endl;
}

int main()
{
    int tamanio=100;
    char diccionario[tamanio]={};
    char palabra[tamanio]={};

    visualizar(diccionario,tamanio);

    printf("%s","Dame una palabra\n");
    scanf("%s",palabra);
    fflush(stdin);
    strcpy(diccionario,palabra);
    strcat(diccionario,"-");
    visualizar(diccionario,tamanio);

    while(strlen(diccionario)<=100)
    {
        printf("%s","Dame otra palabra\n");
        scanf("%s",palabra);
        fflush(stdin);
        strcat(diccionario,palabra);
        strcat(diccionario,"-");
        visualizar(diccionario,tamanio);
    }

    return 0;
}
