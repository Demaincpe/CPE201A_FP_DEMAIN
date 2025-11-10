#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double weight, cost;

    cout << "Enter the weight of parcel (max 1000g): ";
    cin >> weight;

    if (weight <= 0) {
        cout << "Invalid weight." << endl;
    }
    else if (weight > 1000) {
        cout << "You already exceeded a maximum allowed weight (1000g). Please try again." << endl;
    }
    else {
        if (weight <= 300) {
            cost = 5.00;
        }
        else {
            int extraWeight = weight - 300;
            int extraUnits = ceil(extraWeight / 100.0);
            cost = 5.00 + extraUnits * 2.00;
        }

        cout << "Total cost: P" << cost << endl;
    }

    return 0;
}
