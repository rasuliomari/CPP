#include <iostream>
#include <string>
using namespace std;

int main()
{
    int fruit;
    float kilograms, price, totalCost;
    bool validChoice = false;
    cout << "====== G5 HOTEL FRUIT STAND ======" << endl;
    cout << "Available Fruits:" << endl;
    cout << "1. Apples - Tshs 2000 per kg" << endl;
    cout << "2. Bananas - Tshs 1500 per kg" << endl;
    cout << "3. Cherries - Tshs 3000 per kg" << endl;
    do{
        cout << "\nEnter the fruit you want to buy (1-3): ";
        cin >> fruit;
        if (fruit == 1){
            price = 2000;
            cout << "You selected Apples." << endl;
            validChoice = true;}
        else if (fruit == 2){
            price = 1500;
            cout << "You selected Bananas." << endl;
            validChoice = true;}
        else if (fruit == 3){
            price = 3000;
            cout << "You selected Cherries." << endl;
            validChoice = true;}
        else{
            cout << "Invalid fruit type! Please select 1, 2, or 3." << endl;}
    } while (!validChoice);


    cout << "Enter the number of kilograms you want to buy: ";
    cin >> kilograms;

    if (kilograms <= 0){
        cout << "Invalid quantity!" << endl;
        return 0;}

    totalCost = kilograms * price;

    cout << "\n========== PURCHASE DETAILS ==========" << endl;

    if (fruit == 1)
        cout << "Fruit Selected : Apples" << endl;
    else if (fruit == 2)
        cout << "Fruit Selected : Bananas" << endl;
    else
        cout << "Fruit Selected : Cherries" << endl;

    cout << "Quantity       : " << kilograms << " kg" << endl;
    cout << "Price per Kg   : Tshs " << price << endl;
    cout << "Total Cost     : Tshs " << totalCost << endl;
    cout << "======================================" << endl;

    return 0;
}