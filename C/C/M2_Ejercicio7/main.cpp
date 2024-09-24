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

void visualizarVocales( char* palabra, const char* vocales)
{
    bool found = false;
    cout<<"[ ";
    for( int i = 0; i < strlen(palabra); i++) {
        found = false;
        for( int s = 0; s < strlen(vocales) && !found; s++ ) {
            if ( palabra[i] == vocales[s]) {
                cout<<palabra[i];
                found = true;
            }
        }
    }
    cout<<" ]"<<endl;
}

void visualizarConsonantes(char* palabra, const char* consonantes)
{
    bool found = false;
    cout<<"[ ";
    for( int i = 0; i < strlen(palabra); i++) {
        found = false;
        for( int s = 0; s < strlen(consonantes) && !found; s++ ) {
            if ( palabra[i] == consonantes[s]) {
                cout<<palabra[i];
                found = true;
            }
        }
    }
    cout<<" ]"<<endl;
}

void visualizarDigitos(char* palabra){
    cout<<"[ ";
    for( int indx = 0; indx < strlen(palabra); indx++)
    {
        if ( palabra[indx] >= 48 && palabra[indx] < 58)
        cout<< palabra[indx];
    }
    cout<<" ]"<<endl;
}

int main()
{
    int tamanio=200;
    char diccionario[tamanio]={};
    char palabra[tamanio]={};
    const char vocales[]= "aeiouAEIOU";
    const char consonantes[]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','w','z','B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','W','Z'};
    int contador;


    visualizar(diccionario,tamanio);

    printf("%s","Dame una palabra\n");
    scanf("%s",palabra);
    fflush(stdin);
    strcpy(diccionario,palabra);
    visualizar(diccionario,tamanio);
    visualizarVocales(diccionario,vocales);
    visualizarConsonantes(diccionario,consonantes);
    visualizarDigitos(diccionario);

    while(strlen(diccionario)<=200)
    {
        printf("%s","Dame otra palabra\n");
        scanf("%s",palabra);
        fflush(stdin);
        strcat(diccionario,palabra);
        visualizar(diccionario,tamanio);
        visualizarVocales(diccionario,vocales);
        visualizarConsonantes(diccionario,consonantes);
        visualizarDigitos(diccionario);
    }

    return 0;
}
