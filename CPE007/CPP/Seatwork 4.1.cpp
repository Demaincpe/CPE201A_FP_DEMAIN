#include <iostream>
using namespace std;

int main() {
    // array declaration
    int scores[10] = {90, 85, 78, 88, 92, 80, 75, 80, 89, 91};

    // print the 5th element of the array
    cout << scores[4] << endl;

    // change the value of first element to 95
    scores[0] = 95;
    cout << "new value of the scores[0]: " << scores[0] << endl;

    // printing the whole array
    for (int i = 0; i < 10; i++) {
        cout << scores[i] << " ";
    }
    // swapping variables:
    int var1 = 10;
    int var2 = 20;

    int temp = var1;
    var1 = var2;
    var2 = temp;

    // swapping elements on an array:
    temp = scores[0];
    scores[0] = scores[9];
    scores[9] = temp;

    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << scores[i] << " ";
    }

    // bubble sort
    int n = 10;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (scores[j] > scores[j + 1]) {
            	// swap scores[j] and scores[j+1]
                temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    // print sorted array
    cout << "\nScores in ascending order: \n";
    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
        cout << endl;
    }
    return 0;
}
