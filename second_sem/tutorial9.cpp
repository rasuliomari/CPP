#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userName;
    int books;
    const int MAX_BOOKS = 10;

    cout << "===== CHIMWAGA LIBRARY BORROWING SYSTEM =====" << endl;
    cout << "Enter your name: ";
    cin >> userName;
    cout << "Enter number of books you want to borrow: ";
    cin >> books;

    if (books <= 0){
        cout << "Invalid number of books!" << endl;}
    else if (books <= MAX_BOOKS){
        cout << "\nBorrowing Approved!" << endl;
        cout << "User Name       : " << userName << endl;
        cout << "Books Borrowed  : " << books << endl;
        cout << "Please return the books on time." << endl;}
    else{
        cout << "\nBorrowing Denied!" << endl;
        cout << "A user cannot borrow more than 10 books at a time." << endl;}

    return 0;
}