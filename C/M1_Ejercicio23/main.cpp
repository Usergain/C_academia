#include <iostream>

using namespace std;

bool esmayor(int a, int b){
    if(a<b){
        return true;
    }else
        return false;
}

int maximo(int a, int b, int c){
    if(a>b & a>c){
        return a;
    }
    else if(b>a & b>c){
        return b;
    }else
        return c;
}

int minimo(int a, int b , int c){
     if(a<b & a<c){
        return a;
    }
    else if(b<a & b<c){
        return b;
    }else
        return c;
}

bool iguales(int a, int b, int c){
    if(a==b && a==c){
        return true;
    }else
        return false;
}

bool esPar(int a){
    if(a%2 == 0){
        return true;
    }else
        return false;
}

bool esMultiplo(int v, int m){
    if(v%m==0){ //si el resto es 0
        return true;
    }else
        return false;
}
int main()
{
    cout << esmayor(9,4) << endl;
    cout << esmayor(4,9) << endl;
    cout << maximo(7,8,9) << endl;
    cout << maximo(9,8,7) << endl;
    cout << maximo(7,11,9) << endl;
    cout << minimo(7,8,9) << endl;
    cout << minimo(9,8,7) << endl;
    cout << minimo(7,11,9) << endl;
    cout << iguales(7,7,7) << endl;
    cout << iguales(7,8,7) << endl;
    cout << iguales(7,7,8) << endl;
    cout << iguales(8,7,7) << endl;
    cout << esPar(8) << endl;
    cout << esPar(9) << endl;
    cout << esMultiplo(9,3) << endl;
    cout << esMultiplo(11,3) << endl;

    return 0;
}
