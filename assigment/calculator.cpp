#include <iostream>
using namespace std;

int main() {
    double T25_03_17792, majengo, nice;
    char horten;
    cout <<"========== WELCOME TO CALCULATOR ==========" << endl;
    cout <<"Enter first number: ";
    cin >> T25_03_17792;
    cout <<"Enter second number: ";
    cin >> majengo;
    cout <<"Enter the operator (+, -, *, /): ";
    cin >> horten;
    if(horten == '+') {
        nice = T25_03_17792 + majengo;
        cout <<"Result: " << nice << endl;
    } else if(horten == '-') {
        nice = T25_03_17792 - majengo;
        cout <<"Result: " << nice << endl;
    } else if(horten == '*') {
        nice = T25_03_17792 * majengo;
        cout <<"Result: " << nice << endl;
    } else if(horten == '/') {
        if(majengo != 0) {
            nice = T25_03_17792 / majengo;
            cout <<"Result: " << nice << endl;
        } else {
            cout <<"Error: Division by zero!" << endl;
        }
    } else {
        cout <<"Error: Invalid operator!" << endl;
    }

}