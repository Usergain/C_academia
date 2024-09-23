#include <iostream>

using namespace std;

int main()
{
    for(int i=1; i<=10; i++){
        for(int m=0 ; m<=10; m++){
            int total=i*m;
            cout <<total<<"\t";
        }
        cout<<endl<<endl;
   }
   return 0;
}
