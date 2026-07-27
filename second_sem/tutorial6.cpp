#include <iostream>
#include <string>
using namespace std;

int main()
{
    string Name;
    float Basic_Salary, Overtime, Absent;
    float Bonus, NET_PAY;
    float calculatedHours;

    cout << "Enter employee name: ";
    cin >> Name;
    cout << "Enter basic salary: ";
    cin >> Basic_Salary;
    cout << "Enter overtime hours: ";
    cin >> Overtime;
    cout << "Enter absent hours: ";
    cin >> Absent;

    calculatedHours = Overtime - ((2.0 / 3.0) * Absent);

    if (calculatedHours > 40){Bonus = 100000;}
    else if (calculatedHours > 30){Bonus = 60000;}
    else if (calculatedHours > 20){Bonus = 45000;}
    else if (calculatedHours > 10){Bonus = 35000;}
    else{Bonus = 25000;}

    NET_PAY = Basic_Salary + Bonus;

    cout << "\n========== EMPLOYEE PAYMENT REPORT ==========" << endl;
    cout << "Employee Name     : " << Name << endl;
    cout << "Basic Salary      : Tsh " << Basic_Salary << endl;
    cout << "Overtime Hours    : " << Overtime << endl;
    cout << "Absent Hours      : " << Absent << endl;
    cout << "Adjusted Hours    : " << calculatedHours << endl;
    cout << "Bonus Payment     : Tsh " << Bonus << endl;
    cout << "Net Pay           : Tsh " << NET_PAY << endl;
    cout << "=============================================" << endl;

    return 0;
}