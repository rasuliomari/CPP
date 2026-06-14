#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    float x, y, z;
    cout<<"=====WELCOME TO THE PROGRAM THAT WILL TAKE TWO NUMBERS AND MULTIPLY THEM!====="<<endl;
    cout<<" "<< endl;
    cout<<"Please enter the first number: ";
    cin>>x;
    cout<<"Please enter the second number: ";
    cin>>y;
    z = x * y;
    cout<<" "<< endl;
    cout<<"The result of multiplying "<<x<<" and "<<y<<" is: "<<z<<endl;

    ofstream outFile("T25_03_17792.txt");
    outFile<<"The first number is: "<<x<<endl;
    outFile<<"The second number is: "<<y<<endl;
    outFile<<"The result of multiplying "<<x<<" and "<<y<<" is: "<<z<<endl;
    outFile.close();


    return 0;
}