#include <iostream>
using namespace std;

int main() {
    int choice;
    float units, price = 2000.00, amount_to_pay;

    cout << "WELCOME TO THE DUWAS COMPANY LIMITED" << endl;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Calculate bill" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter the number of units used: ";
            cin >> units;

            amount_to_pay = units * price;

            if (units < 5) {
                float vat = amount_to_pay * 18 / 100;
                float total = amount_to_pay + vat;

                cout << "The total price is: " << amount_to_pay << endl;
                cout << "The VAT (18%) is: " << vat << endl;
                cout << "The total amount to pay is: " << total << endl;
            } else {
                float vat = amount_to_pay * 5 / 100;
                float total = amount_to_pay + vat;

                cout << "The total price is: " << amount_to_pay << endl;
                cout << "The VAT (5%) is: " << vat << endl;
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