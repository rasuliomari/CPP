#include <iostream>
using namespace std;

int main() {
    int day;
    cout << "Enter day number (1-7): ";
    cin >> day;
    switch(day) {
        case 1:
            cout << "You enter number 1 and the day you choose is Monday";
            break;
        case 2:
            cout << "You enter number 2 and the day you choose is Tuesday";
            break;
        case 3:
            cout << "You enter number 3 and the day you choose is Wednesday";
            break;
        case 4:
            cout << "You enter number 4 and the day you choose is Thursday";
            break;
        case 5:
            cout << "You enter number 5 and the day you choose is Friday";
            break;
        case 6:
            cout << "You enter number 6 and the day you choose is Saturday";
            break;
        case 7:
            cout << "You enter number 7 and the day you choose is Sunday";
            break;
        default:
            cout << "Invalid day";
    }
    return 0;
}