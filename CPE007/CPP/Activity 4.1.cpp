#include <iostream>
using namespace std;

int main() {
    int physics, biology, math;
    float total, percentage;
    char grade;

    cout << "Physics: ";
    cin >> physics;
    cout << "Biology: ";
    cin >> biology;
    cout << "Math: ";
    cin >> math;

    total = physics + biology + math;
    percentage = total / 3.0;

    cout << "------------" << endl;
    cout << "Average is: " << percentage << "%" << endl;

    switch ((int)percentage / 10) {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        case 5:
        case 4:
            grade = 'E';
            break;
        default:
            grade = 'F';
            break;
    }

    cout << "Grade Level: " << grade << endl;

    return 0;
}
