#include <iostream>
using namespace std;

int main()
{
    float score, sum = 0, average;
    
    cout << "===== CP 111 TEST ONE CLASS PERFORMANCE =====" << endl;

    cout << "Enter student score (Enter negative value to stop): ";
    cin >> score;
    int count = 0;
    while (score >= 0){
        sum = sum + score; 
        count++;     

        cout << "Enter student score (Enter negative value to stop): ";
        cin >> score;}

    if (count > 0){
        average = sum / count;

        cout << "\n========== RESULT ==========" << endl;
        cout << "Number of Students : " << count << endl;
        cout << "Total Score        : " << sum << endl;
        cout << "Average Score      : " << average << endl;
        cout << "============================" << endl;}
    else{
        cout << "No student scores were entered." << endl;}

    return 0;
}