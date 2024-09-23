#include <stdio.h>
#include <string.h>

#define MAX_LONGITUD 20

typedef struct {
    char nombre[MAX_LONGITUD];
    char descripcion[MAX_LONGITUD];
    float precio;
    int cantidad;
} Articulo;

int existe_nombre(Articulo a, FILE *archivo);

int main() {
    Articulo articulo;
    FILE *archivo;
    int existe;

    printf("Ingrese el nombre del artículo: ");
    fgets(articulo.nombre, MAX_LONGITUD, stdin);
    articulo.nombre[strcspn(articulo.nombre, "\n")] = 0;

    printf("Ingrese la descripción del artículo: ");
    fgets(articulo.descripcion, MAX_LONGITUD, stdin);
    articulo.descripcion[strcspn(articulo.descripcion, "\n")] = 0;

    printf("Ingrese el precio del artículo: ");
    scanf("%f", &articulo.precio);
    getchar();

    printf("Ingrese la cantidad de artículos: ");
    scanf("%d", &articulo.cantidad);
    getchar();

    archivo = fopen("articulos.dat", "rb");

    if (archivo == NULL) {
        archivo = fopen("articulos.dat", "wb");
        fwrite(&articulo, sizeof(Articulo), 1, archivo);
        fclose(archivo);
        printf("El artículo se ha guardado en el archivo \"articulos.dat\".\n");
        return 0;
    }

    existe = existe_nombre(articulo, archivo);

    if (existe) {
        printf("El nombre del artículo ya existe en el archivo.\n");
    } else {
        archivo = freopen("articulos.dat", "ab", archivo);
        fwrite(&articulo, sizeof(Articulo), 1, archivo);
        fclose(archivo);
        printf("El artículo se ha guardado en el archivo \"articulos.dat\".\n");
    }

    return 0;
}

int existe_nombre(Articulo a, FILE *archivo) {
    Articulo temp;
    rewind(archivo);

    while (fread(&temp, sizeof(Articulo), 1, archivo)) {
        if (strcmp(a.nombre, temp.nombre) == 0) {
            return 1;
        }
    }

    return 0;
}
