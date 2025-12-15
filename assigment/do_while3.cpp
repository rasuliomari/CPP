#include <iostream>
using namespace std;

int main(){
    int n = 5;
    int i=1;
    do{
        n=n+i;
        cout << "The value of n = " << n << endl;
        i++;
    }while( i<=5);

    return 0;
}