#include <iostream>
using namespace std;

int main()
{
    float income, hourlyRate, charge;
    int timeMinutes;

    cout << "===== HITZ ACCOUNTING FIRM =====" << endl;
    cout << "Enter your income: ";
    cin >> income;
    cout << "Enter consulting time (minutes): ";
    cin >> timeMinutes;

    cout << "Enter regular hourly rate: ";
    cin >> hourlyRate;

    if (income <= 25000)
    {
        if (timeMinutes <= 30)
        {
            charge = 0;
        }
        else
        {
            charge = 0.40 * hourlyRate * ((timeMinutes - 30) / 60.0);
        }
    }
    else
    {
        if (timeMinutes <= 20)
        {
            charge = 0;
        }
        else
        {
            charge = 0.70 * hourlyRate * ((timeMinutes - 20) / 60.0);
        }
    }

    cout << "\n===== BILLING REPORT =====" << endl;
    cout << "Income             : " << income << endl;
    cout << "Consulting Time    : " << timeMinutes << " minutes" << endl;
    cout << "Hourly Rate        : " << hourlyRate << endl;
    cout << "Service Charge     : " << charge << endl;

    return 0;
}