#ifndef LEETCODE_NQUEENS_H
#define LEETCODE_NQUEENS_H


#include <vector>
#include <string>
#include <unordered_map>
#include <set>

class NQueens {
public:
    void markUnsafe(std::vector<std::string> &board, int i, int j,
                     std::set<std::pair<int, int>> &unsafe) {
        for(int y = 0; y < board[i].size(); y++) {  //marking row unsafe
            unsafe.emplace(i, y);
        }

        for (int x = 0; x < board.size(); ++x) {    //marking column unsafe
            unsafe.emplace(x, j);
        }

        int x = i-1;
        int y = j-1;
        while (x >= 0 && y >= 0) {      //upper left diagonal
            unsafe.emplace(x,y);
            x--;
            y--;
        }
        x = i-1;
        y = j+1;
        while (x >= 0 && y < board[i].size()) {     //upper right diagonal
            unsafe.emplace(x,y);
            x--;
            y++;
        }
        x = i+1;
        y = j-1;
        while (x < board.size() && y >= 0) {    //lower left diagonal
            unsafe.emplace(x,y);
            x++;
            y--;
        }

        x = i+1;
        y = j+1;
        while (x < board.size() && y < board[i].size()) {   //lower right diagonal
            unsafe.emplace(x,y);
            x++;
            y++;
        }
    }

    bool isSafe(std::vector<std::string> &board, int row, int col) { //works but TC very high!
        std::set<std::pair<int, int>> unsafe;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'Q') {
                    markUnsafe(board, i, j, unsafe);
                }
            }
        }
        if (unsafe.find({row, col}) == unsafe.end()) {
            return true;
        }
        return false;
    }

    bool isSafe2(std::vector<std::string> &board, int row, int col, int n) {
        for (int y = 0; y < board[row].size(); ++y) {       //row
            if (board[row][y] == 'Q') {
                return false;
            }
        }

        for (int x = 0; x < board.size(); ++x) {        //col
            if (board[x][col] == 'Q') {
                return false;
            }
        }
        int x = row-1;
        int y = col-1;
        while (x >= 0 && y >= 0) {      //upper left diagonal
            if (board[x--][y--] == 'Q') {
                return false;
            }
        }
        x = row-1;
        y = col+1;
        while (x >= 0 && y < board[row].size()) {   //upper right diagonal
            if (board[x--][y++] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void placeQueens(std::vector<std::string> &board, int row, int n,
                     std::vector<std::vector<std::string>> &ans) {  // O(n!)
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; ++i) {
            //if (isSafe(board, row, i)) {   //TC O(n^2)
            if (isSafe2(board, row, i, n)) {    //O(n)
                board[row][i] = 'Q';
                placeQueens(board, row+1, n, ans);
                board[row][i] = '.';
            }

        }

    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        std::vector<std::vector<std::string>> ans;

        placeQueens(board, 0, n, ans);  // O(n!*n^2) or O(n!*n)
        return ans;
    }
};


#endif //LEETCODE_NQUEENS_H
