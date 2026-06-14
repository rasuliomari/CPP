#include <iostream>
using namespace std;

int main() {
    int numbers[6]; 
    cout << "Enter 6 numbers:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Enter number for index  " << i << ": ";
        cin >> numbers[i];
    }

    cout << "\nYou entered:" << endl;
        for (int i = 0; i < 6; i++) {
            cout << numbers[i] << " ";
    }
    cout << endl;
return 0;
}