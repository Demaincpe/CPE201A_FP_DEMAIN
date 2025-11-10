#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double accountnumber, beginningbalance, totalcharges, totalcredit = 0, creditlimit, balance;

    while (true) {
        cout << "Enter account number (-1 to end): ";
        cin >> accountnumber;
        if (accountnumber <= -1) {
            cout << "Account Number not valid!" << endl;
            break;
        }

        cout << "Enter beginning balance: ";
        cin >> beginningbalance;
        cout << "Enter total charges: ";
        cin >> totalcharges;
        cout << "Enter total credits: ";
        cin >> totalcredit;
        cout << "Enter credit limit: ";
        cin >> creditlimit;

        cout << "Account: " << accountnumber << endl;
        balance = beginningbalance + totalcharges - totalcredit;
        cout << "Credit limit: " << creditlimit << endl;
        cout << "Balance: " << balance << endl;

        if (balance > creditlimit) {
            cout << "Credit Limit Exceeded\n";
        }
        cout << endl;
    }

    return 0;
}
