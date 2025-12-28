#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;
    int genderChoice;
    string fullName, place, gender, phone;
    float units, price = 2000.00, amount_to_pay;

    cout << "WELCOME TO THE DUWAS COMPANY LIMITED\n" << endl;
    
    cout << "Enter your full name: ";
    getline(cin, fullName);

    cout << "Enter your place of living: ";
    getline(cin, place);

    cout << "Enter your phone number: ";
    getline(cin, phone);

    cout << "\nSelect your gender:" << endl;
    cout << "1. Male" << endl;
    cout << "2. Female" << endl;
    cout << "Enter choice: ";
    cin >> genderChoice;

    if (genderChoice == 1)
        gender = "Male";
    else if (genderChoice == 2)
        gender = "Female";
    else
        cout << "Invalid gender choice. Proceeding without gender info." << endl;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Generate Bill" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter the number of units used: ";
            cin >> units;

            amount_to_pay = units * price;

            float vat, total;

            if (units < 5) {
                vat = amount_to_pay * 18 / 100;
            } else {
                vat = amount_to_pay * 5 / 100;
            }

            total = amount_to_pay + vat;

            // Display bill
            cout << "\n----- CUSTOMER BILL -----" << endl;
            cout << "Full Name     : " << fullName << endl;
            cout << "Gender        : " << gender << endl;
            cout << "Place         : " << place << endl;
            cout << "Phone Number  : " << phone << endl;
            cout << "Units Used    : " << units << endl;
            cout << "Price per Unit: " << price << endl;
            cout << "Total Price   : " << amount_to_pay << endl;
            cout << "VAT           : " << vat << endl;
            cout << "Amount to Pay : " << total << endl;
        }
        else if (choice == 2) {
            cout << "\nTHANK YOU FOR USING OUR SERVICES" << endl;
        }
        else {
            cout << "\nInvalid choice! Try again." << endl;
        }

    } while (choice != 2);

    return 0;
}
