#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // 1. Write with ofstream
    ofstream out("marks.txt");
    out << "Ali 95\nSara 88";
    out.close();

    // 2. Read with ifstream
    ifstream in("marks.txt");
    string name;
    int marks;
    
    while(in >> name >> marks) {
        cout << name << " scored " << marks << endl;
    }
    in.close();
}