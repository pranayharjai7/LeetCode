#ifndef LEETCODE_ROTTINGORANGES_H
#define LEETCODE_ROTTINGORANGES_H


#include <vector>
#include <queue>
#include <iostream>

class RottingOranges {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> q;
        int rSize = grid.size();
        int cSize = grid[0].size();

        int freshCount = 0;
        for (int i = 0; i < rSize; ++i) {
            for (int j = 0; j < cSize; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;

        int minutes = 0;
        while (!q.empty()) {
            int currQSize = q.size();
            bool rotted = false;
            for (int i = 0; i < currQSize; ++i) {
                auto coords = q.front();
                q.pop();

                std::vector<std::pair<int, int>> neighbors;
                neighbors.emplace_back(coords.first, coords.second-1);
                neighbors.emplace_back(coords.first, coords.second+1);
                neighbors.emplace_back(coords.first-1, coords.second);
                neighbors.emplace_back(coords.first+1, coords.second);

                for (auto &neighbor : neighbors) {
                    if (neighbor.first >=0 && neighbor.first < rSize &&
                    neighbor.second>=0 && neighbor.second < cSize) {
                        if (grid[neighbor.first][neighbor.second] == 1) {
                            grid[neighbor.first][neighbor.second] = 2;
                            q.emplace(neighbor.first, neighbor.second);
                            freshCount--;
                            rotted = true;  // for last case when all are rotted, rotted is false
                        }
                    }
                }
            }

            if (rotted) minutes++;
        }

        if (freshCount == 0) {
            return minutes;
        }
        return -1;
    }

    void solution() {
        std::vector<std::vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
        int minutes = orangesRotting(grid);
        std::cout<< "Rotten Oranges in minutes: " << minutes << std::endl;
    }

};


#endif //LEETCODE_ROTTINGORANGES_H
