#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int numeroAleatorio(){
int aleatorio;

aleatorio= 1 + rand() % (10 + 1 - 1);

}

int main()
{
    int num;

    cout << "Vamos a jugar al juego del acertijo numerico" << endl;
    srand(time(NULL)); //inicializa la semilla
    //for(int i=0; i<10;i++){
        int x= numeroAleatorio();
        //cout <<x<<"\n";
   //}
    // aqui deberia ir el metodo que genera un numero aleatorio.
    do{
        cout << "Dame un numero" << endl;
        cin >> num;
        if(num  > x)
        {
            cout << "El numero introducido es mayor al numero generado." << endl;
        }
        else if(num < x)
        {
            cout << "El numero introducido es menor al numero generado." << endl;
        }
        else
            cout << "Felicidades has adivinado el numero." <<endl;

    }while(num!=x);

    return 0;
}
