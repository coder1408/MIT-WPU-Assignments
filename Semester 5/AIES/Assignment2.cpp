#include <stdio.h>
#include <algorithm>
using namespace std;

// Returns a value based on who is winning
// b[3][3] is the Tic-Tac-Toe board
int evaluate(char b[3][3]) {
    // Checking for Rows for X or O victory.
    for (int row = 0; row < 3; row++) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
            if (b[row][0] == 'x')
                return +10; // X wins
            else if (b[row][0] == 'o')
                return -10; // O wins
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col < 3; col++) {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
            if (b[0][col] == 'x')
                return +10; // X wins
            else if (b[0][col] == 'o')
                return -10; // O wins
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == 'x')
            return +10; // X wins
        else if (b[0][0] == 'o')
            return -10; // O wins
    }
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == 'x')
            return +10; // X wins
        else if (b[0][2] == 'o')
            return -10; // O wins
    }

    // No one has won yet
    return 0;
}

int main() {
    char board[3][3] = {
        {'x', 'o', 'x'},
        {'o', 'x', 'o'},
        {'o', 'x', 'x'}
    };

    int score = evaluate(board);
    if (score == 10) {
        printf("X wins!\n");
    } else if (score == -10) {
        printf("O wins!\n");
    } else {
        printf("It's a draw or the game is ongoing.\n");
    }

    return 0;
}
