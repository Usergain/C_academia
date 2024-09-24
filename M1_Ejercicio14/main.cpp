#include <iostream>
#include <string.h>

using namespace std;

int main()
{
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
        int i = 1;
        do
        {
            cout << " password incorrecto, intentelo de nuevo ip" << endl;
            cin >> password2;
            passwordcomp = strcmp( password, password2);
            i++;
        } while ( i < 5 && passwordcomp != 0 );
        if(passwordcomp == 0) {
            cout << " Bienvenido a CIPSA " << endl;
        } else {
            cout << " Adios !! Has introducido 5 veces mal el password " << endl;
        }
    }
    else
        cout << " usuario incorrecto, adios!! " << endl;
}
