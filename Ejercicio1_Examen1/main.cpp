#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
char nombre[10];
float calificacion;
float maxCalificacion=0;
char nombreMejorCalificacion[10];
float minCalificacion;
char nombreMenorCalificacion[10];
float sumatorioCalificacion;
float mediaCalificacion=0;
int contador=0;

cout << "Dame el nombre del alumno:" << endl;
cin >> nombre;
cout << "Dame la nota del alumno:" << endl;
cin >> calificacion;
while( calificacion >= 0) {
    contador++;
    sumatorioCalificacion += calificacion;
    if(contador==1){
        minCalificacion=calificacion;
        maxCalificacion=calificacion;
        strcpy(nombreMejorCalificacion,nombre);
        strcpy(nombreMenorCalificacion,nombre);
    }
    else if(calificacion>maxCalificacion){
        maxCalificacion=calificacion;
        strcpy(nombreMejorCalificacion,nombre);
    }
    else if(calificacion<minCalificacion){
        minCalificacion=calificacion;
        strcpy(nombreMenorCalificacion,nombre);
    }
    cout << "Dame el nombre del alumno:" << endl;
    cin >> nombre;
    cout << "Dame la nota del alumno:" << endl;
    cin >> calificacion;
}
mediaCalificacion=sumatorioCalificacion/contador;
cout << "El numero de calificaciones introducidas es: " << contador << endl;
cout << "La mejor calificacion es: " << maxCalificacion << " del alumno " << nombreMejorCalificacion << endl;
cout << "La menor calificacion es: " << minCalificacion << " del alumno " << nombreMenorCalificacion << endl;
cout << "La media de las calificaciones es: " << mediaCalificacion << endl;


/*
do{
   cout << "Dame el nombre del alumno:" << endl;
   cin >> nombre;
   cout << "Dame la nota del alumno:" << endl;
   cin >> calificacion;

   if(calificacion>0){
        contador++;
        sumatorioCalificacion += calificacion;
        mediaCalificacion=sumatorioCalificacion/contador;
        if(contador==1){
            minCalificacion=calificacion;
            maxCalificacion=calificacion;
            strcpy(nombreMejorCalificacion,nombre);
            strcpy(nombreMenorCalificacion,nombre);
        }
        else if(calificacion>maxCalificacion){
            maxCalificacion=calificacion;
            strcpy(nombreMejorCalificacion,nombre);
        }
        else if(calificacion<minCalificacion){
            minCalificacion=calificacion;
            strcpy(nombreMenorCalificacion,nombre);
        }
    }
}while(calificacion>=0);
*/
cout << "El numero de calificaciones introducidas es: " << contador << endl;
cout << "La mejor calificacion es: " << maxCalificacion << " del alumno " << nombreMejorCalificacion << endl;
cout << "La menor calificacion es: " << minCalificacion << " del alumno " << nombreMenorCalificacion << endl;
cout << "La media de las calificaciones es: " << mediaCalificacion << endl;

return 0;
}
