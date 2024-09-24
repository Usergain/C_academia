#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODIGO 14
#define MAX_NOMBRE 32

// Definimos estructura de artículo
typedef struct
{
    char codigo[MAX_CODIGO];
    char nombre[MAX_NOMBRE];
    float precio;
    int stock;
} Articulo;

// Función para verificar si un codigo ya existe en el archivo
int existe_nombre(Articulo a, FILE *archivo)
{
    Articulo temp; //los datos del archivo se guardan en esta variable temporal para luego compararlos con el codigo ingresado
    rewind(archivo); //rewind sirve para posicionar el puntero al inicio del archivo
    // fseek(archivo, 0, SEEK_SET); // fseek sirve para posicionar el puntero en una posición específica del archivo

    while (fread(&temp, sizeof(Articulo), 1, archivo))
    {
        if (strcmp(a.codigo, temp.codigo) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// Función para dar de alta un artículo
void altaArticulo()
{
    Articulo a;
    FILE *archivo; 
    int existe;

    printf("************ ALTA ARTICULO **************\n");
    printf("Ingrese el codigo:");
    fgets(a.codigo, MAX_CODIGO, stdin);    // Leer el código del artículo del teclado y guardarlo en el archivo
    a.codigo[strcspn(a.codigo, "\n")] = 0; // Eliminar el salto de línea del final de la cadena

    printf("Ingrese el nombre:");
    fgets(a.nombre, MAX_NOMBRE, stdin);
    a.nombre[strcspn(a.nombre, "\n")];

    printf("Ingrese el precio:");
    scanf("%f", &a.precio);
    getchar(); // getchar sirve para limpiar el buffer de entrada

    printf("Ingrese el stock:");
    scanf("%i", &a.stock); 
    getchar();

    archivo = fopen("almacen.dat", "rb");

    if (archivo == NULL)
    {
        archivo = fopen("almacen.dat", "wb");
        fwrite(&a, sizeof(Articulo), 1, archivo);
        fclose(archivo);
        printf("El articulo se ha guardado en el archivo \"almacen.dat\".\n");
        return; 
    }

    existe = existe_nombre(a, archivo);

    if (existe)
    {
        printf("El nombre del articulo ya existe en el archivo.\n");
    }
    else
    {
        archivo = freopen("almacen.dat", "ab", archivo);
        fwrite(&a, sizeof(Articulo), 1, archivo);
        fclose(archivo);
        printf("El articulo se ha guardado en el archivo \"almacen.dat\".\n");
    }
}

// Función para listar todos los artículos
void listarArticulo()
{
    Articulo temp;
    FILE *archivo; 

    archivo = fopen("almacen.dat", "rb+");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("***************** LISTADO DE ARTICULOS *****************\n");
    printf("%-15s %-15s %-15s %-15s\n", "Codigo", "Nombre", "Precio", "Stock");
    while (fread(&temp, sizeof(Articulo), 1, archivo))
    {
        printf("%-15s %-15s %-15.2f %-15d\n", temp.codigo, temp.nombre, temp.precio, temp.stock);
    }
    fclose(archivo);
}

// función para consultar un artículo
void consultarArticulo()
{
    char codigo[MAX_CODIGO];
    Articulo temp;
    FILE *archivo = fopen("almacen.dat", "rb");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("************ CONSULTA DE ARTICULOS **************\n");
    printf("Ingrese el código del artículo a buscar: ");
    fgets(codigo, MAX_CODIGO, stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    // Buscar el artículo en el archivo
    while (fread(&temp, sizeof(Articulo), 1, archivo) == 1)
    {
        if (strcmp(codigo, temp.codigo) == 0)
        {
            printf("Código: %s\n", temp.codigo);
            printf("Nombre: %s\n", temp.nombre);
            printf("Precio: %.2f\n", temp.precio);
            printf("Stock: %d\n", temp.stock);
            fclose(archivo);
            return;
        }
    }

    printf("El artículo no encontrado.\n");
}

// Función para listar los artículos con stock bajo
void listarArticuloBajoStock()
{
    Articulo temp;
    FILE *archivo = fopen("almacen.dat", "rb");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
    }

    printf("************ ARTICULOS CON STOCK BAJO **************\n");
    printf("%-15s %-15s %-15s %-15s\n", "Codigo", "Nombre", "Precio", "Stock");
    while (fread(&temp, sizeof(Articulo), 1, archivo) == 1)
    {
        if (temp.stock == 0)
        {
            printf("%-15s %-15s %-15.2f %-15d\n", temp.codigo, temp.nombre, temp.precio, temp.stock);
        }
        else{
            printf("No hay articulos con stock bajo.\n");
        }
    }
    fclose(archivo);
}

// función para reponer artículos
void reponerArticulo()
{
    char codigo[MAX_CODIGO];
    int cantidad=0;
    int encontrado;
    Articulo temp;

    FILE *archivo = fopen("almacen.dat", "rb+");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("************ REPONER ARTICULOS **************\n");
    printf("Ingrese el código del artículo a reponer: ");
    fgets(codigo, MAX_CODIGO, stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    // Buscar el artículo en el archivo
    while (fread(&temp, sizeof(Articulo), 1, archivo) == 1)
    {
        if (strcmp(codigo, temp.codigo) == 0)
        {
            encontrado = 1;
            printf("Articulo encontrado: \n");
            break;
        }
    }

    if (encontrado)
    {
        printf("Añadir la cantidad de stock a reponer: \n");
        scanf("%d", &cantidad);
        temp.stock += cantidad;
        fseek(archivo, -sizeof(Articulo), SEEK_CUR); // retroceder el puntero
        fwrite(&temp, sizeof(Articulo), 1, archivo); // sobreescribir el registro
        printf("Stock actualizado correctamente.\n");
    }

    else
    {
        printf("El articulo no existe.\n");
    }
    fclose(archivo);
}

// función para vender artículos
void venderArticulo()
{
    char codigo[MAX_CODIGO];
    int cantidad;
    int encontrado = 0;
    Articulo temp;

    FILE *archivo = fopen("almacen.dat", "rb+");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("************ VENDER ARTICULOS **************\n");
    printf("Ingrese el código del artículo: ");
    fgets(codigo, MAX_CODIGO, stdin);
    codigo[strcspn(codigo, "\n")] = 0;

    // Buscar ek articulo en el archivo
    while (fread(&temp, sizeof(Articulo), 1, archivo) == 1)
    {
        if (strcmp(temp.codigo, codigo) == 0)
        {
            encontrado = 1;
            printf("Articulo encontrado.\n");
            break;
        }
    }

    if (!encontrado)
    {
        printf("Articulo no encontrado.\n");
    }

    else
    {
        printf("Cantidad a vender: \n");
        scanf("%d", &cantidad);
        if (cantidad > temp.stock)
        {
            printf("Stock insuficiente.\n");
        }

        else
        {
            temp.stock -= cantidad;
            fseek(archivo, -sizeof(Articulo), SEEK_CUR); 
            fwrite(&temp, sizeof(Articulo), 1, archivo);
            printf("Venta realizada correctamente.\n");

        }
    }
    fclose(archivo);
}

int main()
{
    int opcion;
    do
    {
        printf("************* GESTION DE ALMACEN ****************\n");
        printf("1. Alta articulo\n");
        printf("2. Listado de articulos\n");
        printf("3. Consulta de articulos\n");
        printf("4. Articulos con stock bajo\n");
        printf("5. Reponer articulos\n");
        printf("6. Vender articulo\n");
        printf("0. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        getchar(); // Limpiar el buffer de entrada

        switch (opcion)
        {
        case 1:
            altaArticulo();
            break;
        case 2:
            listarArticulo();
            break;
        case 3:
            consultarArticulo();
            break;
        case 4:
            listarArticuloBajoStock();
            break;
        case 5:
            reponerArticulo();
            break;
        case 6:
            venderArticulo();
            break;
        case 0:
            printf("Saliendo del programa...");
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
    } while (opcion != 0);
    return 0;
}