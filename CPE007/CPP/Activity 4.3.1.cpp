#include <iostream>
#include <string>
using namespace std;

int main() {
    string letters[2][8] = {
        {"R", "N", "B", "Q", "K", "B", "N", "R"},
        {"P", "P", "P", "P", "P", "P", "P", "P"}
    };
    for (int j = 0; j < 8; j++) {
        cout << letters[0][j] << " ";
    }
    cout << endl;
    for (int j = 0; j < 8; j++) {
        cout << letters[1][j] << " ";
	}
    cout << endl << endl << endl << endl << endl;
    for (int j = 0; j < 8; j++) {
        cout << letters[1][j] << " ";
    }
    cout << endl;
    for (int j = 0; j < 8; j++) {
        cout << letters[0][j] << " ";
    }
	return 0;
}
