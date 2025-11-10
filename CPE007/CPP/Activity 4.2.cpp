#include <iostream>
using namespace std;

int main() {
    int d = 10;
    int temp;
    int grades[d] = {93, 91, 97, 96, 94, 89, 99, 98, 92, 95};

    // array printing
    for (int i = 0; i < d; i++) {
        cout << grades[i] << " ";
    }

    cout << endl;

    // Bubble Sort
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d - i - 1; j++) {
            if (grades[j] > grades[j + 1]) {
                temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
            }
        }
    }

    // sorted data printing
    for (int i = 0; i < d; i++) {
        cout << grades[i] << " ";
    }

    return 0;
}
