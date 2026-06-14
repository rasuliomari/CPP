#include <iostream>
using namespace std;

int main() {
    int x;      // normal variable
    int *y;     // pointer variable

    x = 7;      // store value in x
    y = &x;     // store address of x in y

    cout << "Step 1: Value of x = " << x << endl;
    cout << "Step 2: Address of x (&x) = " << &x << endl;
    cout << "Step 3: Value of y (stores address of x) = " << y << endl;
    cout << "Step 4: Value pointed by y (*y) = " << *y << endl;

    return 0;
}