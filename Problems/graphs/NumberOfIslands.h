#ifndef LEETCODE_NUMBEROFISLANDS_H
#define LEETCODE_NUMBEROFISLANDS_H


#include <vector>
#include <iostream>
#include <queue>

class NumberOfIslands {
public:

    void DFS(std::vector<std::vector<char>> &grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return;
        }
        if (grid[r][c] == '0') {
            return;
        }

        // convert the 1s to 0s
        // so that in next iteration of numIslands(), it doesn't get detected as an island.
        grid[r][c] = '0';

        DFS(grid, r, c - 1);
        DFS(grid, r, c + 1);
        DFS(grid, r - 1, c);
        DFS(grid, r + 1, c);
    }

    void BFS(std::vector<std::vector<char>> &grid, int r, int c) {
        //It modifies the grid, saves space
        //a visited[][] could also be used but it would consume space O(m*n)
        std::queue<std::pair<int, int>> q;
        q.emplace(r, c);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            std::vector<std::pair<int, int>> neighbors;
            neighbors.emplace_back(curr.first, curr.second - 1);
            neighbors.emplace_back(curr.first, curr.second + 1);
            neighbors.emplace_back(curr.first - 1, curr.second);
            neighbors.emplace_back(curr.first + 1, curr.second);

            for (int i = 0; i < neighbors.size(); ++i) {
                if (neighbors[i].first >= 0 && neighbors[i].first < grid.size() &&
                    neighbors[i].second >= 0 && neighbors[i].second < grid[0].size()) {
                    if (grid[neighbors[i].first][neighbors[i].second] == '1') {
                        grid[neighbors[i].first][neighbors[i].second] = '0';
                        q.emplace(neighbors[i].first, neighbors[i].second);
                    }
                }
            }

        }
    }

    int numIslands(std::vector<std::vector<char>> &grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    //DFS(grid, i, j);
                    //OR
                    BFS(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

    void solution() {
        std::vector<std::vector<char>> grid = {
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}
        };
        std::cout << "Number of Islands: " << numIslands(grid) << std::endl;
    }
};


#endif //LEETCODE_NUMBEROFISLANDS_H
