#include <iostream>
using namespace std;

int main()
{
    int level, score;
    string grade;

    cout << "STUDENT GRADING SYSTEM" << endl;
    cout << "1. Pre-grade-one" << endl;
    cout << "2. Pre-grade-two" << endl;

    cout << "\nEnter education level (1 or 2): ";
    cin >> level;

    cout << "Enter student's score (0-100): ";
    cin >> score;

    // Validate score
    if (score < 0 || score > 100){
        cout << "Invalid score!" << endl;
        return 0;}
    if (level == 1){
        if (score <= 19)
            {grade = "E";}
        else if (score <= 39)
            {grade = "D";}
        else if (score <= 59)
            {grade = "C";}
        else if (score <= 79)
            {grade = "B";}
        else
            {grade = "A";}
    }
    else if (level == 2){
        if (score <= 19)
            {grade = "E";}
        else if (score <= 39)
            {grade = "D";}
        else if (score <= 59)
            {grade = "C";}
        else if (score <= 69)
            {grade = "B";}
        else if (score <= 79)
            {grade = "B+";}
        else
            {grade = "A";}
        }
    else{
        cout << "Invalid education level!" << endl;
        return 0;
    }

    cout << "\nStudent Grade: " << grade << endl;

    return 0;
}