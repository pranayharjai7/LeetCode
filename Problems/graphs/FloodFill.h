#ifndef LEETCODE_FLOODFILL_H
#define LEETCODE_FLOODFILL_H


#include <vector>
#include <queue>
#include <iostream>

class FloodFill {
public:
    void floodFill(std::vector<std::vector<int>> &bitmap, int x, int y) {
        if (bitmap[x][y] == 1) {
            return;
        }

        std::queue<std::pair<int, int>> q;
        q.emplace(x, y);

        while (!q.empty()) {
            auto coords = q.front();
            q.pop();

            bitmap[coords.first][coords.second] = 1;

            std::vector<std::pair<int, int>> neighbors;
            neighbors.emplace_back(coords.first, coords.second-1);
            neighbors.emplace_back(coords.first, coords.second+1);
            neighbors.emplace_back(coords.first-1, coords.second);
            neighbors.emplace_back(coords.first+1, coords.second);

            for( auto &n: neighbors) {
                if (n.first < 0 || n.first >= bitmap.size() ||
                    n.second < 0 || n.second >= bitmap[n.first].size() ||
                    bitmap[n.first][n.second] == 1) {
                    continue;
                }

                q.emplace(n.first, n.second);
            }
        }
    }

    void solution() {
        std::vector<std::vector<int>> bitmap = {{1,1,1,1,1,0,1,1,1,1},
                                                {1,0,1,0,1,0,1,0,0,0},
                                                {1,0,1,0,1,0,0,0,0,0},
                                                {1,0,1,1,1,1,1,1,0,0},
                                                {1,1,1,1,0,1,0,0,0,0}};
        int x = 2;
        int y = 5;
        floodFill(bitmap, x, y);
        std::cout << std::endl;
        for (auto &row: bitmap) {
            for (auto &i: row) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    }
};


#endif //LEETCODE_FLOODFILL_H
