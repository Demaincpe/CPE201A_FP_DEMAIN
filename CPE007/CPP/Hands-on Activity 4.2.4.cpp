#include <iostream>
using namespace std;

int main() {
    const int RESPONSE_SIZE = 40;
    int responses[RESPONSE_SIZE] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10, 1, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 6, 8, 6, 6, 5, 6, 6, 5, 6, 7, 5, 6, 4, 8, 6, 8, 10};
    cout << "Response Summary:" << endl;
    int number[11] = {0}; 
    for (int i = 0; i < RESPONSE_SIZE; i++) {
        number[responses[i]]++;
    }
    for (int i = 1; i < 11; i++) {
        cout << "Response " << i << ": " << number[i] << " students" << endl;
    }

    return 0;
}
