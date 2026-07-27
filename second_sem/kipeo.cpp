#include <iostream>
using namespace std;

// Function kipeo
int kipeo(int num) {
    return num * num; // calculates square
}

int main() {
    const int SIZE = 5; // you can change size. Example: 10 numbers
    int squares[SIZE];
    int number;

    for(int i = 0; i < SIZE; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> number;

        squares[i] = kipeo(number); // call function and store result
    }

    cout << "\nSquares of the numbers are: " << endl;
    for(int i = 0; i < SIZE; i++) {
        cout << "squares[" << i << "] = " << squares[i] << endl;
    }

    return 0;
}