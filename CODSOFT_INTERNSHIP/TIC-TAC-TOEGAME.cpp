#include <iostream>
#include <vector>

char checkWinner(const std::vector<char>& board) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i * 3] != ' ' && board[i * 3] == board[i * 3 + 1] && board[i * 3] == board[i * 3 + 2]) {
            return board[i * 3];
        }
        if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i + 6]) {
            return board[i];
        }
    }
    if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8]) {
        return board[0];
    }
    if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6]) {
        return board[2];
    }
    return ' ';
}

void printBoard(const std::vector<char>& board) {
    std::cout << "Current board:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << " " << board[i * 3] << " | " << board[i * 3 + 1] << " | " << board[i * 3 + 2] << "\n";
        if (i < 2) std::cout << "---|---|---\n";
    }
}

int main() {
    std::vector<char> board(9, ' ');
    char currentPlayer = 'X';
    int moveCount = 0;

    while (true) {
        printBoard(board);
        int move;
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        std::cin >> move;

        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move - 1] = currentPlayer;
        moveCount++;

        char winner = checkWinner(board);
        if (winner != ' ') {
            printBoard(board);
            std::cout << "Player " << winner << " wins!\n";
            break;
        }
        
        if (moveCount == 9) {
            printBoard(board);
            std::cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}