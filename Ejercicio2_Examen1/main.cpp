#include <iostream>
#include <stdlib.h>

using namespace std;

int counter2(int a, int b){
    int i;
    if(a < b) {
        for(i=a; i<=b; i++){
            cout<<i<<"-";
        }
    } else {
        for(i=b; i<=a; i++){
            cout<<i<<"-";
        }
    }
}

int counter(int a, int b){
    int max, min;
    if(a>b){
        max=a; min=b;
    }
    else{
        max=b; min=a;
    }

    for(int i=min; i<=max; i++){
        cout<<i<<" ";
    }
    cout<<"\n";
}

int main()
{
    int a,b;
    cout<<"Ingrese numero: "<<endl;
    cin >>a;
    cout<<"Ingrese numero: "<<endl;
    cin >>b;

    cout<< "los numeros comprendidos de " <<a<< " hacia "<<b<< " son: ";
    counter(a,b);

    return 0;
}
