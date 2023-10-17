#include <iostream>
#include <vector>

void printBoard(const std::vector<char>& board) {
    for (char c : board) {
        std::cout << c;
    }
    std::cout << std::endl;
}

bool isMoveValid(const std::vector<char>& board, int index, char color, int n) {
    if (index < 0 || index >= 2 * n + 1 || board[index] != ' ') {
        return false;
    }
    if (color == 'R' && index > 0 && board[index - 1] == 'G') {
        return true;
    }
    if (color == 'G' && index < 2 * n && board[index + 1] == 'R') {
        return true;
    }
    return false;
}

bool solvePuzzle(std::vector<char>& board, int movesLeft, int n) {
    if (movesLeft == 0) {
        printBoard(board);
        return true;
    }

    for (int i = 0; i < 2 * n + 1; ++i) {
        if (isMoveValid(board, i, 'R', n)) {
            board[i] = 'R';
            if (solvePuzzle(board, movesLeft - 1, n)) {
                return true;
            }
            board[i] = ' ';
        }

        if (isMoveValid(board, i, 'G', n)) {
            board[i] = 'G';
            if (solvePuzzle(board, movesLeft - 1, n)) {
                return true;
            }
            board[i] = ' ';
        }
    }

    return false;
}

int main() {
    int n = 2;
    int totalMoves = 2 * n;
    std::vector<char> board(2 * n + 1, ' ');

    board[0] = 'R'; // Initial position of Red marbles
    board[2 * n] = 'G'; // Initial position of Green marbles

    std::cout << "Possible Solutions:" << std::endl;
    solvePuzzle(board, totalMoves, n);

    return 0;
}
