#include <iostream>
#include <string>
using namespace std;

int main() {
    int i = 0;
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    while (i >= 0) {
        cout << "What is the day today? ";
        cin >> i;
        if (i >= 0 && i < 7) {
            cout << days[i] << endl;
        } else {
            cout << "Error, no such day." << endl;
        }
    }

    return 0;
}
