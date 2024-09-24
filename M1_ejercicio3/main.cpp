#include <iostream>

using namespace std;

int main()
{
    float a;
    float c;
    float x;
    float y;
    float z;

    cout << "Dame el valor de x " << endl;
    cin >> x ;
    cout << "Dame el valor de y " << endl;
    cin >> y;
    cout << "Dame el valor de z " << endl;
    cin >> z;
    a = (x+y)/(x-y);
    c = (x+(y/z))/(x-(y/z));
    cout << "El resultado de (x+y)/(x-y) es: " << a << endl;
    cout << "El resultado de (x+(y/z))/(x-(y/z) es: " << c << endl;
    return 0;
}
