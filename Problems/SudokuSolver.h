#ifndef LEETCODE_SUDOKUSOLVER_H
#define LEETCODE_SUDOKUSOLVER_H


#include <vector>

class SudokuSolver {
public:
    bool checkIfValid(std::vector<std::vector<char>> &board, int row, int col) {    //O(n)
        char currVal = board[row][col];
        for (int y = 0; y < board[row].size(); ++y) {   //check for same value in the current row
            if (y != col) {         //skipping the currVal
                if (board[row][y] == currVal) {
                    return false;
                }
            }
        }

        for (int x = 0; x < board.size(); ++x) {    //check for same value in the current column
            if (x != row) {         //skipping currVal
                if (board[x][col] == currVal) {
                    return false;
                }
            }
        }

        //For the current block,
        //divide row/3: ans = 0,1,2
        //divide col/3: ans = 0,1,2
        //this can suggest which block to check
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (i == row && j == col) {     //skipping the currVal
                    continue;
                }
                if (board[i][j] == currVal) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(std::vector<std::vector<char>> &board) { //total TC: O(n^3)
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    if (!checkIfValid(board, i, j)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool solveSudoku2(std::vector<std::vector<char>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; ++digit) {
                        board[i][j] = digit;
                        if (checkIfValid(board, i, j)) {
                            if (solveSudoku2(board)) {
                                return true;    // Continue with the next cells
                            }
                        }
                        board[i][j] = '.';      // Backtrack if not valid
                    }
                    return false;               // If no number is valid, return false
                }
            }
        }

        return true;                            // All cells are filled correctly
    }


    //same as above function checkIfValid(). just currVal changed to digit, and no need to skip digit
    bool isSafeToPlace(std::vector<std::vector<char>> &board, int row, int col, char digit) {
        for (int y = 0; y < board[row].size(); ++y) {   //check for same value in the current row
            if (board[row][y] == digit) {
                return false;
            }
        }

        for (int x = 0; x < board.size(); ++x) {    //check for same value in the current column
            if (board[x][col] == digit) {
                return false;
            }
        }

        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = startRow; i < startRow + 3; ++i) {     //check for same value in the current block
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }

    bool sudokuSolver(std::vector<std::vector<char>> &board, int row, int col) {
        if (row == board.size()) {
            return true;
        }
        if (col == board.size()) {
            return sudokuSolver(board, row + 1, 0);
        }
        if (board[row][col] != '.') {
            return sudokuSolver(board, row, col + 1);
        }
        for (char digit = '1'; digit <= '9'; ++digit) {     //when it is an empty place
            if (isSafeToPlace(board, row, col, digit)) {
                board[row][col] = digit;
                if (sudokuSolver(board, row, col + 1)) {
                    return true;
                }
                board[row][col] = '.';  //backtrack and reset
            }
        }
        return false;
    }

    void solveSudoku(std::vector<std::vector<char>> &board) {
        sudokuSolver(board, 0, 0);
        //OR
        solveSudoku2(board);
    }
};


#endif //LEETCODE_SUDOKUSOLVER_H
