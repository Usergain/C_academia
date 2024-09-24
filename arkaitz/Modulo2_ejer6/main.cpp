#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    /*
    Esto funciona pero al compilar el uso de string genera más codigo de compilación y más basurilla por ende para uso de sistemas embebidos,
    microprocesadores, etc usaría demasiados recursos, no valdría

    char clave[20];
    char nombre[20];
    char nomVer[7];
    char passVer[6];
    int i;
    string user;
    string password;

    cout << "Dame nombre " << endl;
    cin >> user ;
    cout << "Dame password " << endl;
    cin >> password ;

    if(user == "alumno" && password == "cipsa")
    {
        cout << " Bienvenido a CIPSA " << endl;
    }
    else if(nombre == "alumno" && password != "cipsa")
    {
        cout << " password incorrecto, intentelo de nuevo " << endl;
    }
    else if(nombre != "alumno" && password == "cipsa")
    {
        cout << " usuario incorrecto, intentelo de nuevo " << endl;
    }
    else
        cout << " usuario y contraseña incorrecto, intentelo de nuevo " << endl;

    return 0;*/

    char user [] = "alumno";
    char password [] = "cipsa";
    char user2 [10];
    char password2 [10];

    cout << "Dame nombre " << endl;
    cin >> user2 ;
    cout << "Dame password " << endl;
    cin >> password2 ;

    int usercmp = strcmp(user, user2);
    int passwordcomp = strcmp(password, password2);

    if(usercmp == 0 && passwordcomp == 0)
    {
        cout << " Bienvenido a CIPSA " << endl;
    }
    else if(usercmp == 0 && passwordcomp != 0)
    {
        cout << " password incorrecto, intentelo de nuevo " << endl;
    }
    else if(usercmp != 0 && passwordcomp == 0)
    {
        cout << " usuario incorrecto, intentelo de nuevo " << endl;
    }
    else
        cout << " usuario y contraseña incorrecto, intentelo de nuevo " << endl;
}
