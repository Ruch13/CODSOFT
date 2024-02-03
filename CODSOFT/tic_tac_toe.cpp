#include <iostream>
using namespace std;

// Function prototypes
void displayBoard(char board[3][3]);
bool playerMove(char board[3][3], char currentPlayer);
bool checkWin(char board[3][3], char currentPlayer);
bool checkDraw(char board[3][3]);
void switchPlayers(char &currentPlayer);
void displayResult(char result);
bool playAgain();

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    char result;

    do {
        displayBoard(board);
        bool validMove = playerMove(board, currentPlayer);

        while (!validMove) {
            cout << "Invalid move! Try again.\n";
            validMove = playerMove(board, currentPlayer);
        }

        result = checkWin(board, currentPlayer) ? currentPlayer : (checkDraw(board) ? 'D' : ' ');

        switchPlayers(currentPlayer);

    } while (result == ' ');

    displayBoard(board);
    displayResult(result);

    if (playAgain()) {
        main(); 
    }

    return 0;
}

void displayBoard(char board[3][3]) {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool playerMove(char board[3][3], char currentPlayer) {
    int row, col;
    cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
    cin >> row >> col;

    --row;
    --col;

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

bool checkWin(char board[3][3], char currentPlayer) {
    
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayers(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void displayResult(char result) {
    if (result == 'X' || result == 'O') {
        cout << "Player " << result << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }
}

bool playAgain() {
    char choice;
    cout << "Wanna play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
