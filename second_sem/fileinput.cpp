#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("data.txt");

    int x = 10;
    string name = "Rasuli";

    outFile << x << endl;
    outFile << name << endl;

    outFile.close();

    return 0;
}