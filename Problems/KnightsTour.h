#ifndef LEETCODE_KNIGHTSTOUR_H
#define LEETCODE_KNIGHTSTOUR_H


#include <vector>

class KnightsTour {
public:

    bool gridCheckRec(std::vector<std::vector<int>> &grid, int r, int c, int count) {
        int n = grid.size();
        if (count == (n*n) - 1) {
            return true;
        }

        //check neighbors..
        std::vector<std::pair<int, int>> neighbors;
        neighbors.emplace_back(r+2,c+1);
        neighbors.emplace_back(r+1,c+2);
        neighbors.emplace_back(r-1,c+2);
        neighbors.emplace_back(r-2,c+1);
        neighbors.emplace_back(r-2,c-1);
        neighbors.emplace_back(r-1,c-2);
        neighbors.emplace_back(r+1,c-2);
        neighbors.emplace_back(r+2,c-1);

        for (auto nextJump: neighbors) {
            if (nextJump.first < 0 || nextJump.first >= n || nextJump.second < 0 ||
            nextJump.second >= n || grid[nextJump.first][nextJump.second] != count + 1) {
                continue;
            }
            return gridCheckRec(grid, nextJump.first, nextJump.second, ++count);
        }

        return false;
    }

    bool gridCheckRec2(std::vector<std::vector<int>> &grid, int r, int c, int count) {
        int n = grid.size();

        if (r < 0 || r >= n || c < 0 || c >= n) {
            return false;
        }

        if (grid[r][c] != count) {
            return false;
        }

        if (count == (n*n) - 1) {
            return true;
        }

        bool ans1 = gridCheckRec2(grid, r+2,c+1, count+1);
        bool ans2 = gridCheckRec2(grid, r+1,c+2, count+1);
        bool ans3 = gridCheckRec2(grid, r-1,c+2, count+1);
        bool ans4 = gridCheckRec2(grid, r-2,c+1, count+1);
        bool ans5 = gridCheckRec2(grid, r-2,c-1, count+1);
        bool ans6 = gridCheckRec2(grid, r-1,c-2, count+1);
        bool ans7 = gridCheckRec2(grid, r+1,c-2, count+1);
        bool ans8 = gridCheckRec2(grid, r+2,c-1, count+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(std::vector<std::vector<int>> &grid) {
        if (grid[0][0] != 0) return false;
        return gridCheckRec(grid, 0, 0, grid[0][0]);
    }
};


#endif //LEETCODE_KNIGHTSTOUR_H
