#include <iostream>
using namespace std;

void pokea(int &x, int &y){
    cout << "enter the first number: ";
    cin >> x;
    cout << "enter the second number: ";
    cin >> y;
}
int calcutale(int x, int y){
    return x % y;
}
void display(int x, int y, int result){
    cout << "the remainder of " << x << " and " << y << " is: " << result << endl;
}

int main(){
    int x,y,result;
    pokea(x,y);
    result = calcutale(x,y);
    display(x,y,result);
    return 0;
}