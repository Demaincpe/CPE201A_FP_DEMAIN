#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int scores[size] = {95, 85, 78, 88, 92, 80, 75, 80, 89, 91};
    for (int i = 0; i < size; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "address of elements " << i << ": " << &scores[i] << endl;
    }
    int *scorePtr;
    scorePtr = &scores[9];
    cout << *scorePtr << endl;
    cout << scorePtr << endl;
    int numBytes = sizeof(scores);
    cout << "The number of bytes of this array is: " << numBytes << endl;
    return 0;
} 
