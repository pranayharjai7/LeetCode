#ifndef LEETCODE_THEMAZE_H
#define LEETCODE_THEMAZE_H

#include <vector>
#include <iostream>

/*
 * There is a ball in a maze with empty spaces and walls.
 * The ball can go through empty spaces by rolling up, down, left or right,
 * but it won't stop rolling until hitting a wall.
 * When the ball stops, it could choose the next direction.
 * Given the ball's start position, the destination and the maze, determine whether the ball
 * could stop at the destination.
 */
class TheMaze {
public:

    bool dfs(std::vector<std::vector<int>> &maze, std::pair<int, int> curr,
             std::pair<int, int> &dest, std::vector<std::vector<bool>> &visited) {
        if ((curr.first < 0 || curr.first >= maze.size()) ||
            (curr.second < 0 || curr.second >= maze[curr.first].size())) {
            return false;
        }

        if (curr.first == dest.first && curr.second == dest.second) {
            return true;
        }

        if (visited[curr.first][curr.second]) {
            return false;
        }

        visited[curr.first][curr.second] = true;

        std::vector<std::pair<int, int>> directions;
        directions.emplace_back(0, 1);
        directions.emplace_back(0, -1);
        directions.emplace_back(1, 0);
        directions.emplace_back(-1, 0);

        for (auto &dir: directions) {
            int nextX = curr.first;
            int nextY = curr.second;
            while (nextX + dir.first >= 0 && nextX + dir.first < maze.size() &&     //x coord in limits
                   nextY + dir.second >= 0 && nextY + dir.second < maze[0].size() && //y coord in limits
                   maze[nextX+ dir.first][nextY + dir.second] == 0) {   // maze[x][y] is 0
                nextX += dir.first;
                nextY += dir.second;
            }
            if (dfs(maze, {nextX, nextY}, dest, visited)) {
                return true;
            }
        }

        return false;

    }

    bool isDestinationReachable(std::vector<std::vector<int>> &maze, std::pair<int, int> &start,
                                std::pair<int, int> &dest) {
        std::vector<std::vector<bool>> visited(maze.size(),
                                               std::vector<bool>(maze[0].size(),
                                                                 false));
        return dfs(maze, start, dest, visited);
    }

    void solution() {
        std::vector<std::vector<int>> maze = {{0, 0, 1, 0, 0},
                                              {0, 0, 0, 0, 0},
                                              {0, 0, 0, 1, 0},
                                              {1, 1, 0, 1, 1},
                                              {0, 0, 0, 0, 0}};
        std::pair<int, int> start = {0, 4};
        std::pair<int, int> dest = {4, 4};
        auto ans = isDestinationReachable(maze, start, dest);

        std::cout << "Is the destination reachable by the ball in maze?: " << ans << std::endl;
    }
};


#endif //LEETCODE_THEMAZE_H
