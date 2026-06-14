#include <iostream>
using namespace std;

int main() {
    int choice;
    float usagara, T25_03_17792 = 2000.00, majengo;

    cout << "WELCOME TO THE DUWAS COMPANY LIMITED" << endl;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Calculate bill" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter the number of units used: ";
            cin >> usagara;

            majengo = usagara * T25_03_17792;
            float vat = majengo * 18 / 100;

            if (usagara < 5) {
                float total = majengo + vat;

                cout << "The total price is: " << majengo << endl;
                cout << "The VAT (18%) is: " << vat << endl;
                cout << "The total amount to pay is: " << total << endl;
            } else {
                float vat2 = majengo * 5 / 100;
                float total = majengo + vat2 + vat;

                cout << "The total price is: " << majengo << endl;
                cout << "The VAT (5%) is: " << vat2 << endl;
                cout << "The total amount to pay is: " << total << endl;
            }
        }
        else if (choice == 2) {
            cout << "\nTHANK YOU FOR USING OUR SERVICES" << endl;
        }
        else {
            cout << "\nInvalid choice! Please try again." << endl;
        }

    } while (choice != 2);

    return 0;
}