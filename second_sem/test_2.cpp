#include <iostream>

using namespace std;

int main() {

    cout<<"Welcome to enter the numbers into an array of size 7 as follows: "<<endl;
    float aziza[7];
    float product = 1;
    int omari = 0;
    while (omari<7)
    {
        cout<<"Enter the "<<omari+1<<" number: ";
        cin>>aziza[omari];
        omari++;
    }
    cout<<endl;
    for(int T25_03_17792=0; T25_03_17792<7; T25_03_17792++)
    {
        product = product * aziza[T25_03_17792];
    }
    cout<<"\nThe product of the numbers from the array is: "<<product<<endl;
    return 0;
}