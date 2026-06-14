#include <iostream>
using namespace std;    
int main() {
    int array[6];
    int r = 0;
    cout << "Enter 6 numbers:" << endl;
    do{
        cout << "Enter number for index  " << r << ": ";
        cin >> array[r];
        r++;
    }
    while (r<6);    

    cout << "\nYou entered:" << endl;
    r = 0;
    do{
        cout << array[r] << " ";
        r++;
    }
    while (r<6);
    cout << endl;
    return 0;
}