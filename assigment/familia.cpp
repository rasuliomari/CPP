#include <iostream>
using namespace std;    
int main() {
    int T25_03_17792[3];
    cout << "Enter 3 numbers:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Enter number for index " << i << ": ";
        cin >> T25_03_17792[i];
    }
    cout << "\nYou entered:" << endl;
    cout <<" ";
    int i = 0;
    while (i < 3)
    {
        cout<< T25_03_17792[i] << " ";
        i++;
    }
    
    cout << endl;
    return 0;
}