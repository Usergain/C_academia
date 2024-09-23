#include <stdio.h>
#include <stdlib.h>
#define MAX_CUENTAS 5
#define true 1
#define false 0

typedef struct Cliente
{
    char dni[10];
    char nombre[50];
    int edad;
} Cliente;

Cliente *banco = NULL;
int banco_clientes = 0;

int menu()
{
    int ok = false;
    int opcion;
    do
    {
        puts("OPCIONES");
        puts("1.- Alta Cliente");
        puts("2.- Listas Clientees");
        puts("0.- Salir");
        scanf("%d", &opcion);
        ok = (opcion >= 0 && opcion <= 2) ? true : false;
    } while (!ok);
    return opcion;
}

void nuevo_Cliente()
{
    if (banco_clientes < MAX_CUENTAS)
    {
        if (banco_clientes == 0)
        {
            banco = (Cliente *)malloc(sizeof(Cliente));
        }
        else
        {
            banco = (Cliente *)realloc(banco, sizeof(Cliente) * banco_clientes);
        }
        puts("Indica el DNI: ");
        scanf("%s", banco[banco_clientes].dni);
        puts("Indica el Nombre: ");
        scanf("%s", banco[banco_clientes].nombre);
        puts("Indica la edad: ");
        scanf(" %d", &(banco[banco_clientes].edad));
        banco_clientes++;
        puts("CLIENTE ALMACENADO.");
    }
    else
        puts("No hay espacio disponible");
}

void listar_Clientees()
{
    if (banco_clientes > 0)
    {
        int indx;
        for (indx = 0; indx < banco_clientes; indx++)
        {
            printf("%d.-\t DNI: \t%s\tNOMBRE %s\t\t EDAD: %d\n",
                   indx,
                   banco[indx].dni,
                   banco[indx].nombre,
                   banco[indx].edad);
        }
        puts("FIN DE LISTADO.");
    }
    else
        puts("NO HAY ClienteES.");
}

int main(void)
{
    int opcion;
    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1:
        {
            nuevo_Cliente();
        };
        break;
        case 2:
        {
            listar_Clientees();
        };
        break;
        }
    } while (opcion != 0);
    puts("FIN DE PROGRAMA.");
    free(banco);
    return EXIT_SUCCESS;
}
