#include <iostream>
using namespace std;

/*int main(){
    float a,b,result;
    char op, desition;

    do {
    cout << "Enter two numbers: ";
    cin >> a;
    cin >> b;
    cout << "Enter operator (1 for addition, 2 for subtraction, 3 for multiplication, 4 for division): ";
    cin >> op;
        switch(op){
            case '1':
                result = a + b;
                break;
            case '2':
                if(b>=a){
                    result = b - a;
                }
                else{
                    result = a - b;
                }
                break;
            case '3':
                result = a * b;
                break;
            case '4':
                if(b!=0){
                    result = a / b;
                }
                else{
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid operator!" << endl;
        }
        cout << "Result: " << result << endl;
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> desition;
    } while(desition == 'y' || desition == 'Y');
    return 0;
}
*/


int main() {
    float a, b, result;
    int op;
    char decision;
    int i = 0;
    do {
        cout << "Enter two numbers: ";
        cin >> a >> b;

        cout << "Enter operator (1:Add, 2:Subtract, 3:Multiply, 4:Divide): ";
        cin >> op;

        bool valid = true;

        switch(op) {
            case 1:
                result = a + b;
                break;

            case 2:
                result = a - b;
                break;

            case 3:
                result = a * b;
                break;

            case 4:
                if(b != 0)
                    result = a / b;
                else {
                    cout << "Error: Division by zero!" << endl;
                    valid = false;
                }
                break;

            default:
                cout << "Invalid operator!" << endl;
                valid = false;
        }

        if(valid)
            cout << "Result: " << result << endl;

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> decision;
        i++;

    } while(decision == 'y' || decision == 'Y');

    return 0;
}