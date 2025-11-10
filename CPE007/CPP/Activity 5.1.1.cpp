#include <iostream>

using namespace std;

int main()
{
    int col, i, j, num;
    cout << "Multiplication Table from 1 to 10:\n\n";

    for (i = 1; i <= 10; i++)
    {
        col = i;
        for (j = 1; j <= 10; j++)
        {
            num = col * j;
            cout << num << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}
