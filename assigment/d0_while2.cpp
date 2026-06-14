#include <iostream>
using namespace std;

int main(){
    int array[6]={9,8,7,6,5,4};
    int r = 0;
    cout << "The array are: ";
    do
    {
       cout << array[r] <<"    " ; 
       r++;
    }
    while (r<6);
    cout << endl;
    
    return 0;
}