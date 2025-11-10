#include <iostream>
using namespace std;

int main() {
    int n[10] = {19, 3, 15, 7, 11, 9, 13, 5, 17, 1};
    cout << "Element      Value      Histogram" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "\t" << i << "\t" << n[i] << "\t";
        for (int j = 0; j < n[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
