#include <iostream>
using namespace std;

int main(){
    float units, price= 2000.00, amount_to_pay, answer;
    cout << "WELCOME TO THE DUWAS COMPANY LIMITED" << endl;
    cout << " " << endl;
    cout << "Enter the number of units that used: ";
    cin >> units;
    amount_to_pay = units * price;
    if (units<5){
        float vat = amount_to_pay * 18 / 100;
        answer = amount_to_pay + vat ;
        cout << "The total price is: " << amount_to_pay << endl;
        cout << "The VAT is: " << vat << endl;
        cout << "The total amount to pay and vat is: " << answer<< endl;
    }
    else{
        float vat2 = amount_to_pay * 5 / 100;
        answer = amount_to_pay + vat2 ;
        cout << "The total price is: " << amount_to_pay << endl;
        cout << "The VAT is: " << vat2 << endl;
        cout << "The total amount to pay and vat is: " << answer << endl;
    }
    cout << " " << endl;
    cout << "THANK YOU FOR USING OUR SERVICES" << endl; 
    return 0;
}