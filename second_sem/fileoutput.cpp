#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("data.txt");

    int x;
    string name;

    inFile >> x;
    inFile >> name;

    cout << x << endl;
    cout << name << endl;

    inFile.close();

    return 0;
}