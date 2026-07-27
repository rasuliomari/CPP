/*#include <iostream>
using namespace std;
/*
// Returns nothing, just prints
void printMarks(string name, int marks) {
    cout << name << " scored " << marks << endl;
}

// Returns nothing, just changes data
void recordMarks(int &marks) {
    marks = 95; // modifies original because of &
}

int main() {
    printMarks("Ali", 88); // Output: Ali scored 88
    
    int s = 0;
    recordMarks(s);
    cout << s; // Output: 95
}*/


/*int main(){
    /*int z = 90;
    z++;
    z++;
    int g = ++z;
    cout << g << endl;
    cout << z << endl;

    int u =20;
    int y = ++u%10;
    cout << y << endl;
    cout << u << endl;

    cout << "char: " << sizeof(char) << " bytes\n";      // 1
    cout << "int: " << sizeof(int) << " bytes\n";        // 4
    cout << "float: " << sizeof(float) << " bytes\n";    // 4
    cout << "double: " << sizeof(double) << " bytes\n";  // 8
    cout << "string: " << sizeof(string) << " bytes\n";  // 24 or 32*/

   /* int values[] = {10, 20, 30, 40, 50};
    int sum = values[0] + values[1] + values[2] + values[3] + values[4];
    cout << "Sum: " << sum << endl;
}*/

#include <iostream>
using namespace std;

int main() {
    const int BOLTPRICE = 500;
    const int NUTPRICE = 300;
    const int WASHERPRICE = 100;

    int bolts, nuts, washers;
    int totalCost;
    bool errorFound = false;

    cout << "Number of bolts: ";
    cin >> bolts;
    cout << "Number of nuts: ";
    cin >> nuts;
    cout << "Number of washers: ";
    cin >> washers;

    totalCost = (bolts * BOLTPRICE) + (nuts * NUTPRICE) + (washers * WASHERPRICE);

    // Check order
    if (nuts < bolts) {
        cout << "Check the Order: too few nuts" << endl;
        errorFound = true;
    }
    if (washers < 2 * bolts) {
        cout << "Check the Order: too few washers" << endl;
        errorFound = true;
    }
    
    // Only print OK if no errors
    if (errorFound == false) {
        cout << "Order is OK" << endl;
    }

    cout << "Total cost: " << totalCost << endl;

    return 0;
}


