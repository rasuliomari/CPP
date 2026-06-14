#include <iostream>

using namespace std;

int main() {

    cout<<"Welcome to enter the numbers into an array of size 5 as follows: "<<endl;
    double array[5];
    double T25_03_16257 = 1;
    int Rasuli = 0;
    while (Rasuli<5)
    {
        cout<<"Enter the "<<Rasuli+1<<" number: ";
        cin>>array[Rasuli];
        Rasuli++;
    }
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<"The "<<i+1<<" number that you entered is: "<<array[i]<<endl;
        T25_03_16257 = T25_03_16257 * array[i];
    }
    cout<<"\nThe product of the numbers from the arrayis: "<<T25_03_16257<<endl;
    return 0;
}