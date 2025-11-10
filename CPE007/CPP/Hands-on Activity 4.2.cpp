#include <iostream>
using namespace std;

int main() {
    int n[10];

    // Initialize array elements to 0
    for (int i = 0; i < 10; i++) {
        n[i] = 0;
    }

    cout << "Element Value" << endl;

    // Print index and value
    for (int i = 0; i < 10; i++) {
        cout << "   " << i << "      " << n[i] << endl;
    }

    return 0;
}
