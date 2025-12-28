#include <iostream>
using namespace std;

int main(){
    float usagara, majengo, answer;
    int T25_03_17792 = 2000;
    cout << "WELCOME TO THE DUWAS COMPANY LIMITED" << endl;
    cout << " " << endl;
    cout << "Enter the number of units that used: ";
    cin >> usagara;
    majengo = usagara * T25_03_17792;
    float vat = majengo * 18 / 100;
    if (usagara<5){
        answer = majengo + vat ;
        cout << "The total price is: " << majengo << endl;
        cout << "The VAT is: " << vat << endl;
        cout << "The total amount to pay and vat is: " << answer<< endl;
    }
    else{
        float vat2 = majengo * 5 / 100;
        answer = majengo + vat2 + vat  ;
        cout << "The total price is: " << majengo << endl;
        cout << "The VAT is: " << vat2 << endl;
        cout << "The total amount to pay and vat is: " << answer << endl;
    }
    cout << " " << endl;
    cout << "THANK YOU FOR USING OUR SERVICES" << endl; 
    return 0;
}