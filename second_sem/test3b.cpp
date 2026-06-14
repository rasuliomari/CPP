#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    
    // Get input from user
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator (+, -, *, /): ";
    cin >> operation;
    cout << "Enter second number: ";
    cin >> num2;
    
    double result;
    bool validOperation = true;
    
    // Perform the calculation
    switch(operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero!" << endl;
                validOperation = false;
            }
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
            validOperation = false;
    }
    
    if(validOperation) {
        // Create and open a text file to store the result
        ofstream MyFile("calculation_results.txt");
        
        // Write the calculation and result to the file
        MyFile << "First Number: " << num1 << endl;
        MyFile << "Operator: " << operation << endl;
        MyFile << "Second Number: " << num2 << endl;
        MyFile << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
        MyFile << "----------------------------------------" << endl;
       
        
        // Close the file
        MyFile.close();
        
        cout << "\nCalculation result has been saved to 'calculation_results.txt'" << endl;
        
        // Read from the file and display the content
        string myText;
        ifstream MyReadFile("calculation_results.txt");
        
        cout << "\n--- Reading from file ---" << endl;
        if(MyReadFile.is_open()) {
            while(getline(MyReadFile, myText)) {
                cout << myText << endl;
            }
            MyReadFile.close();
        } else {
            cout << "Unable to open file for reading!" << endl;
        }
        
        // Also display the result directly
        cout << "\n--- Direct Result ---" << endl;
        cout << num1 << " " << operation << " " << num2 << " = " << result << endl;
    }
    
    return 0;
}