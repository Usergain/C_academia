#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

char letraDNI(int dni)
{
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";

    return letra[dni%23];
}

short verificaDNI(char *dni)
{
    if (strlen(dni)!=9)
        return 0;
    else
        return (letraDNI(atoi(dni))==dni[8]);
}

int main(int argc, char *argv[])
{
    char dni[20];
    bool flag=false;

    do
    {
        printf("---------------------VALIDADOR DNI-----------------\n\n");
        printf ("Introduce tu DNI con letra (sin espacios): ");
        scanf("%s", dni);

        if (verificaDNI(dni))
        {
            printf ("El DNI es correcto\n");
            flag=true;
        }
        else
            printf ("El DNI no es correcto\n");

    }
    while(flag==false);

    return 0;
}

