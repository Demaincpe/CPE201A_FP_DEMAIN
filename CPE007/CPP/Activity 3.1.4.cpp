#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int choice;
    float radius, length, width, base, height, side;
    const float PI = 3.14159265358979323846;
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        cout << "AREA CALCULATOR MENU\n";
        cout << "1. Area of Circle\n";
        cout << "2. Area of Rectangle\n";
        cout << "3. Area of Triangle\n";
        cout << "4. Area of Square\n";
        cout << "Select 1-4: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter radius: ";
                cin >> radius;
                cout << "Area of Circle: " << PI * radius * radius << endl;
                break;

            case 2:
                cout << "Enter length: ";
                cin >> length;
                cout << "Enter width: ";
                cin >> width;
                cout << "Area of Rectangle: " << length * width << endl;
                break;

            case 3:
                cout << "Enter base: ";
                cin >> base;
                cout << "Enter height: ";
                cin >> height;
                cout << "Area of Triangle: " << 0.5 * base * height << endl;
                break;

            case 4:
                cout << "Enter side: ";
                cin >> side;
                cout << "Area of Square: " << side * side << endl;
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
