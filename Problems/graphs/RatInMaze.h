#ifndef LEETCODE_RATINMAZE_H
#define LEETCODE_RATINMAZE_H


#include <vector>
#include <string>
#include <iostream>

class RatInMaze {
public:

    void solveRec(std::vector<std::vector<int>> &maze, int r, int c,
                  std::vector<std::vector<bool>> &visited, std::string path,
                  std::vector<std::string> &ans, std::pair<int, int> &end) {
        if (r < 0 || c < 0 || r >= maze.size() || c >= maze[r].size()) {
            return;
        }
        if (visited[r][c]) {    //to prevent loops
            return;
        }
        if (maze[r][c] == 0) {  //we don't want to traverse 0
            return;
        }
        if (r == end.first && c == end.second) {    //we reach the destination
            ans.push_back(path);
            return;
        }

        visited[r][c] = true;

        solveRec(maze, r - 1, c, visited, path + "U", ans, end);
        solveRec(maze, r + 1, c, visited, path + "D", ans, end);
        solveRec(maze, r, c - 1, visited, path + "L", ans, end);
        solveRec(maze, r, c + 1, visited, path + "R", ans, end);

        visited[r][c] = false;
    }

    std::vector<std::string> mazeSolver(std::vector<std::vector<int>> &maze,
                                        std::pair<int, int> start,
                                        std::pair<int, int> end) {
        std::vector<std::string> ans;
        std::string path;
        std::vector<std::vector<bool>> visited(maze.size(),
                                               std::vector<bool>(maze[0].size(), false));
        solveRec(maze, start.first, start.second, visited, path, ans, end);
        return ans;
    }

    void solveRec2(std::vector<std::vector<int>> &maze, int r, int c, std::string path,
                  std::vector<std::string> &ans, std::pair<int, int> &end) {
        if (r < 0 || c < 0 || r >= maze.size() || c >= maze[r].size()) {
            return;
        }
        if (maze[r][c] == 0) {  //we don't want to traverse 0
            return;
        }
        if (r == end.first && c == end.second) {    //we reach the destination
            ans.push_back(path);
            return;
        }

        maze[r][c] = 0;

        solveRec2(maze, r - 1, c, path + "U", ans, end);
        solveRec2(maze, r + 1, c, path + "D", ans, end);
        solveRec2(maze, r, c - 1, path + "L", ans, end);
        solveRec2(maze, r, c + 1, path + "R", ans, end);

        maze[r][c] = 1;
    }

    std::vector<std::string> mazeSolver2(std::vector<std::vector<int>> &maze,
                                        std::pair<int, int> start,
                                        std::pair<int, int> end) {
        std::vector<std::string> ans;
        std::string path;
        solveRec2(maze, start.first, start.second, path, ans, end);
        return ans;
    }

    void solution() {
        //given a matrix(nxn) of 0s and 1s
        //find all possible paths from a given source coordinate to reach end coordinate.
        //you can only travel through 1s.
        //allowed moves: 4 directions
        //You have to store the directions used in a string..
        //E.G. "DDRDRR": Down Down Right Down Right Right
        //return the vector of vector of characters of such possible paths.
        std::vector<std::vector<int>> maze = {{1, 0, 0, 0},
                                              {1, 1, 0, 1},
                                              {1, 1, 0, 0},
                                              {0, 1, 1, 1}};
        std::cout << "Rat in maze :: all possible paths:\n";
        auto ans = mazeSolver(maze, {0,0}, {3,3});
        for (int i = 0; i < ans.size(); ++i) {
            std::cout << ans[i] << std::endl;
        }
        std::cout << "Rat in maze :: all possible paths without visited[][]:\n";
        auto ans2 = mazeSolver2(maze, {0,0}, {3,3});
        for (int i = 0; i < ans2.size(); ++i) {
            std::cout << ans2[i] << std::endl;
        }
    }
};


#endif //LEETCODE_RATINMAZE_H
