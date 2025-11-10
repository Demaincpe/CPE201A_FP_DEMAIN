#include <iostream>

using namespace std;

int main() {

    char board[3][3];

    int count = '1';

    // Initialize board

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = count++;

    char player = ' ';

    char currentPlayer = 'X';

    // Display board

    while (player == ' ') {

        cout << "\n";

        for (int i = 0; i < 3; i++) {

            cout << " ";

            for (int j = 0; j < 3; j++) {

                cout << board[i][j];

                if (j < 2) cout << " | ";

            }

            cout << "\n";

            if (i < 2) cout << "---+---+---\n";

        }

        cout << "\n";

        // Player move

        int move;

        cout << "Player " << currentPlayer << ", enter your move (1-9): ";

        cin >> move;

        if (move < 1 || move > 9) {

            cout << "Invalid move. Please try again.\n";

            continue;

        }

        int row = (move - 1) / 3;

        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {

            cout << "Spot already taken. Please try again.\n";

            continue;

        }

        board[row][col] = currentPlayer;

        // Check winner

        for (int i = 0; i < 3; i++) {

            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                player = board[i][0];

            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                player = board[0][i];

        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            player = board[0][0];

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            player = board[0][2];

        // Check for draw

        bool full = true;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    full = false;

        if (player == ' ' && full) player = 'D';

        // Switch player

        if (player == ' ')
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    }

    // Final board

    cout << "\n";

    for (int i = 0; i < 3; i++) {

        cout << " ";

        for (int j = 0; j < 3; j++) {

            cout << board[i][j];

            if (j < 2) cout << " | ";

        }

        cout << "\n";

        if (i < 2) cout << "---+---+---\n";

    }

    cout << "\n";

    // Result

    if (player == 'D')
        cout << "Draw!\n";
    else
        cout << "Player " << player << " wins!\n";

    return 0;

}
