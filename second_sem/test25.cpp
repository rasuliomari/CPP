#include <iostream>
using namespace std;

/*int main() {

    int houseNo[5] = {10,201,76,80,40};
    for (int i = 0; i < 5; i++) {
        cin >> houseNo[i];
    }
    int j = 0;
    while (j < 5) {
        int p = 4-j;
        for (;p>=0; p--) {
            cout << houseNo[p];
        }
        cout<< endl;
        j = j + 2;
    }
    return 0;
}*/
/*int main() {
    int a = 0, b=6;
    string c = "cive";
    char d = '5', e = 'B';
    int *p = NULL;
    string *q = NULL;
    char *n = NULL;
    p = &b;
    n = &e;
    q = &c;
    *p = a;
    *n = d;
    a = 2;
    d = '2';
    *q = "info";
    cout << c <<a <<b <<d <<e;
    //cout << (sizeof(a)+sizeof(e));

    return 0;
}*/

/*string hello(int s){
    string j = "Hello " + s;
    return j;
}
int main () {
    string s, j;
    s = "Rasuli";
    j = hello(s);
    cout << J;
    return 0;
}*/

/*int main () {
    int age;
    for (int i = 0; i < 100; i++) {
        cout << "Enter your age: ";
        cin >> age;
        if (age >= 18) {
            cout << "You are eligible to vote." << endl;
        } else {
            cout << "You are not eligible to vote." << endl;
        }
    }
}*/

/*int sum(int a, int b) {
    int c = a + b;
    return c;
}
int difference(int a, int b) {
    int c = a - b;
    return c;
}*/

/*int main() {
    int x, y,p,q;
    cout << "Enter two numbers: ";
    cin >> x >> y>>p>>q;
    int result = sum(x, y);
    int result2 = difference(p ,q);
    cout << "The sum is: " << result << endl;
    cout << "The difference is: " << result2 << endl;
    return 0;
}*/


// Function to find the square of a number

int kipeo(int a)
{
    int c =  a * a;
    return c;
}

int main()
{
    int numbers[5] = {1, 2, 3, 4, 5};
    int squares[5];

    // Store the squares in the array
    for (int i = 0; i < 5; i++)
    {
        squares[i] = kipeo(numbers[i]);
    }

    // Display the squares
    cout << "Squares of the numbers are: ";
    for (int i = 0; i < 5; i++)
    {
        cout << squares[i] << " ";
    }

    cout << endl;

    return 0;
}

/*void sum(int a, int b) {
    int c = a + b;
    cout << "The sum is: " << c << endl;
}
int main() {
    int x=4;
    int y=5;
    sum(x, y);
    return 0;
}*/

/*void student(string name, int age, float marks)
{
    cout << "Name: " << name << " Age: " << age << " Marks: " << marks << endl;
}

int main()
{
    student("Rasuli", 22, 85.5);
    return 0;
}*/