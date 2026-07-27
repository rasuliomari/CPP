/*#include <iostream>
using namespace std;

int main()
{
    float homework, quiz, exam;
    string highestComponent;

    // Bob's scores
    homework = 78;
    quiz = 88;
    exam = 80;

    // Find the highest score
    if (homework > quiz && homework > exam){
        highestComponent = "Homework";}
    else if (quiz > homework && quiz > exam){
        highestComponent = "Quiz";}
    else{
        highestComponent = "Final Exam";}

    // Display result
    cout << "===== BOB'S SCORE REPORT =====" << endl;
    cout << "Homework Score : " << homework << endl;
    cout << "Quiz Score     : " << quiz << endl;
    cout << "Final Exam     : " << exam << endl;

    cout << "\nHighest Score Component: " << highestComponent << endl;

    return 0;
}*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    float homework, quiz, exam;
    float totalGrade;
    string highestComponent;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter Homework score (0-100): ";
    cin >> homework;
    cout << "Enter Quiz score (0-100): ";
    cin >> quiz;
    cout << "Enter Final Exam score (0-100): ";
    cin >> exam;
    totalGrade = (homework * 0.30) + 
                 (quiz * 0.20) + 
                 (exam * 0.50);
    if (homework > quiz && homework > exam){
        highestComponent = "Homework";}
    else if (quiz > homework && quiz > exam){
        highestComponent = "Quiz";}
    else{
        highestComponent = "Final Exam";}

    cout << "\n========== STUDENT REPORT ==========" << endl;
    cout << "Student Name       : " << name << endl;
    cout << "Homework Score     : " << homework << endl;
    cout << "Quiz Score         : " << quiz << endl;
    cout << "Final Exam Score   : " << exam << endl;

    cout << "Final Grade        : " << totalGrade << "%" << endl;
    cout << "Highest Component  : " << highestComponent << endl;
    cout << "====================================" << endl;


    return 0;
}