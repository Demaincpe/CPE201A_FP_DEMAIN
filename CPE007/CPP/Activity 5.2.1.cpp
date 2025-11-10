#include <iostream>
using namespace std;
bool multiple(int num, int mult) {
    return (num % mult == 0);
}
int main() {
    int num, mult;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter a number to check multiples of: ";
    cin >> mult;
    if (multiple(num, mult)) {
        cout << num << " is a multiple of " << mult << "." << endl;
    }
    else {
        cout << num << " is NOT a multiple of " << mult << "." << endl;
    }
    return 0;
}
