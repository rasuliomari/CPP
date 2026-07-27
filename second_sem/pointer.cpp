#include <iostream>
#include <string>
using namespace std;

int main(){
    int a = 0, b = 6;
    string c = "cive";
    char d = '5', e = 'B';
    int *p = NULL;
    string *q = NULL;
    char *n = NULL;
    p = &b;   // p now points to b
    n = &e;   // n now points to e
    q = &c;   // q now points to c
    *p = a;   // b = 0
    *n = d;   // e = '5'
    a = 2;
    d = '2';
    *q = "info"; // c = "info"
    cout<<c<<a<<b<<d<<e;
return 0;
}   
