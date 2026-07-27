#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int k_zalishwa, k_uzwa;
    float bei, mauzo_jumla, faida;
    int k_bakia, reportID;
    // Generate random report ID
    srand(time(0));
    reportID = rand() % 9000 + 1000;

    cout << "HITZ COMPANY DAILY REPORT SYSTEM\n";
    cout << "Enter total shoes produced: ";
    cin >> k_zalishwa;

    cout << "Enter quantity of shoes sold: ";
    cin >> k_uzwa;

    cout << "Enter selling price per shoe: ";
    cin >> bei;

    // Validation
    if (k_zalishwa < 0 || k_uzwa < 0 || k_uzwa > k_zalishwa || bei < 0){
        cout << "Invalid input!" << endl;
        return 0;
    }
    k_bakia = k_zalishwa - k_uzwa;
    mauzo_jumla = k_uzwa * bei;
    faida = mauzo_jumla * 0.25;

    cout << "\n========== DAILY REPORT ==========" << endl;
    cout << "Report ID          : " << reportID << endl;
    cout << "Partners           : Juma & Jenny" << endl;
    cout << "Shoes Produced     : " << k_zalishwa << endl;
    cout << "Shoes Sold         : " << k_uzwa << endl;
    cout << "Remaining Stock    : " << k_bakia << endl;
    cout << "Total Sales        : " << mauzo_jumla << endl;
    cout << "Total Profit (25%) : " << faida << endl;
    cout << "==================================" << endl;

    return 0;
}