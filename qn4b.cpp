#include <iostream>
using namespace std;

int main(){
    float units, price= 2000.00, amount_to_pay;
    string customer_name, customer_place, customer_phone;
    cout << "WELCOME TO THE DUWAS COMPANY LIMITED" << endl;
    cout << "Enter your name: " << endl;
    cin >> customer_name;
    cout << "Enter your place that you are living: " << endl;
    cin >> customer_place;
    cout << "Enter your phone number: " << endl;
    cin >> customer_phone;
    cout << "Enter the number of units that used: " << endl;
    cin >> units;
    amount_to_pay = units * price;
    cout << " " << endl;
    if (units<5){
        float vat = amount_to_pay * 18 / 100;
        float answer = amount_to_pay + vat ;
        cout << "Customer Name: " << customer_name << endl;
        cout << "Customer Place: " << customer_place << endl;
        cout << "Customer Phone Number: " << customer_phone << endl;
        cout << "The total price is: " << amount_to_pay << endl;
        cout << "The VAT is: " << vat << endl;
        cout << "The total amount to pay and vat is: " << answer<< endl;
    }
    else{   
        float vat2 = amount_to_pay * 5 / 100;
        float answer2 = amount_to_pay + vat2 ;
        cout << "Customer Name: " << customer_name << endl;
        cout << "Customer Place: " << customer_place << endl;
        cout << "Customer Phone Number: " << customer_phone << endl;
        cout << "The total price is: " << amount_to_pay << endl;
        cout << "The VAT is: " << vat2 << endl;
        cout << "The total amount to pay and vat is: " << answer2<< endl;
    }
    cout << " " << endl;
    cout << "THANK YOU FOR USING OUR SERVICES" << endl; 
    return 0;
}