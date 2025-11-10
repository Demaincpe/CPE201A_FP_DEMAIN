#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double gallons, miles, mpg;
    double totalGallons = 0.0, totalMiles = 0.0;
    double overallMPG = 0.0;

    while (true) {
        cout << "Enter the gallons used (-1 to end): ";
        cin >> gallons;

        if (gallons <= 0) {
            break;
        }

        cout << "Enter the miles driven: ";
        cin >> miles;

        mpg = miles / gallons;
        cout << "The miles / gallon for this tank was " << fixed << setprecision(6) << mpg << endl;
        cout << endl;

        totalGallons += gallons;
        totalMiles += miles;
    }

    if (totalGallons > 0) {
        overallMPG = totalMiles / totalGallons;
        cout << "The overall average miles/gallon was " << overallMPG << endl;
    }
    else {
        cout << "No data entered." << endl;
    }

    return 0;
}
