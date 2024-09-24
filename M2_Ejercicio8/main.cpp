#include <iostream>
#include <cstring>

using namespace std;

// Funcion para solicitar nombres y almacenarlos en el arreglo
void solicitarNombres(char nombres[][50], int cantidad)
{
	for (int i = 0; i < cantidad; i++)
	{
		cout << "Ingrese el nombre de la persona " << i + 1 << "; ";
		cin >> nombres[i];
	}
}

// Funcion para ordenar los nombres alfabeticamente utilizando strcmp
void ordenarNombres(char nombres[][50], int cantidad)
{
	char temp[50]; // Variable temporal para intercambiar nombres

	for (int i = 0; i < cantidad - 1; i++)
	{
		for (int j = i + 1; j < cantidad; j++)
		{
			if (strcmp(nombres[i], nombres[j]) > 0)
			{
				strcpy(temp, nombres[i]);
				strcpy(nombres[i], nombres[j]);
				strcpy(nombres[j], temp);
			}
		}
	}
}

/* 
Función para ordenar los nombres alfabéticamente utilizando std::sort

void ordenarNombres(string nombres[], int cantidad) {
	sort(nombres, nombres + cantidad);
}
*/

// Funcion para mostrar los nombres en orden  alfabético
void mostrarNombres(char nombres[][50], int cantidad)
{
	cout << "Nombre en orden alfabetico: " << endl;
	for (int i = 0; i < cantidad; i++)
	{
		cout << nombres[i] << endl;
	}
}

int main()
{
	char nombres[3][50];

	solicitarNombres(nombres, 3);
	ordenarNombres(nombres, 3);
	mostrarNombres(nombres, 3);

	return 0;
}
