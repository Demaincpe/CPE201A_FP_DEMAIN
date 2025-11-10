#include <iostream>
using namespace std;

int main() {
    int choice;
    float value, result;
    char again = 'y';

    const float cm_to_inch = 0.393701;
    const float inch_to_cm = 2.54;
    const float feet_to_meter = 0.3048;
    const float meter_to_feet = 3.28084;

    while (again == 'y' || again == 'Y') {
        cout << "Unit Conversion Menu:\n";
        cout << "1. cm - inch\n";
        cout << "2. inch - cm\n";
        cout << "3. feet - meter\n";
        cout << "4. meter - feet\n";
        cout << "Select 1-4: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter centimeter value: ";
                cin >> value;
                result = value * cm_to_inch;
                cout << value << " cm = " << result << " inch\n";
                break;

            case 2:
                cout << "Enter inch value: ";
                cin >> value;
                result = value * inch_to_cm;
                cout << value << " inch = " << result << " cm\n";
                break;

            case 3:
                cout << "Enter value in feet: ";
                cin >> value;
                result = value * feet_to_meter;
                cout << value << " feet = " << result << " meter\n";
                break;

            case 4:
                cout << "Enter meter value: ";
                cin >> value;
                result = value * meter_to_feet;
                cout << value << " meter = " << result << " feet\n";
                break;

            default:
                cout << "Invalid choice! Please select 1-4 only.\n";
                continue;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> again;
    }

    cout << "Thank you!\n";
    return 0;
}
