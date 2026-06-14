#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter a number to check if it is positive or negative: ";
    cin >> number;

    if (number > 0) {
        cout << "You enter positive number" << endl;
    } else {
        cout << "You enter negative number or zero" << endl;
    }

    return 0;
}