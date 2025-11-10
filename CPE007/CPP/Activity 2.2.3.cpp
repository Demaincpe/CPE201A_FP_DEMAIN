#include <iostream>
using namespace std;

int main() {
    double total = 0;
    int counter = 0;
    double grade;
    double average;

    cout << "Enter grade: ";
    cin >> grade;

    while (grade != -1) {
        total += grade;
        counter++;
        cout << "Enter grade: ";
        cin >> grade;
    }

    if (counter != 0) {
        average = total / counter;
        cout << "Average grade: " << average << endl;
    }
    else {
        cout << "No grades were entered" << endl;
    }

    return 0;
}
