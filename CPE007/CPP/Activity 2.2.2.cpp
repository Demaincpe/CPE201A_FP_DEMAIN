#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    const double minFare = 9.0;
    string studentID;
    int age;
    double discount = 0.0;

    cout << "Do you have a student ID? (yes/no): ";
    getline(cin, studentID);
    for (char &c : studentID) {
        c = tolower(c);
    }

    cout << "Enter your age: ";
    cin >> age;

    if (age >= 60) {
        discount = 0.10;
    }
    else if (studentID == "yes") {
        discount = 0.08;
    }

    double discountedFare = minFare * (1.0 - discount);
    cout << fixed << setprecision(2)
         << "Your fare after discount is: " << discountedFare << " pesos" << endl;

    return 0;
}
