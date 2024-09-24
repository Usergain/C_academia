#include <iostream>

using namespace std;

int main()
{
    int temperatura;

    cout << "Dame una temperatura" << endl;
    cin >> temperatura ;

    if(temperatura > 100)
    {
        cout << "Gaseoso" << endl;
    }
    else if(temperatura < 0)
    {
        cout << "Helado" << endl;
    }
    else
        cout << "liquido" << endl;

    return 0;
}
