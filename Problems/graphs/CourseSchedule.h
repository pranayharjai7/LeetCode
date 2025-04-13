#ifndef LEETCODE_COURSESCHEDULE_H
#define LEETCODE_COURSESCHEDULE_H


#include <vector>
#include <iostream>

class CourseSchedule {
public:
    bool DFS(std::vector<std::vector<int>> &preReqGraph, std::vector<bool> &visited,
             std::vector<bool> &recStack, int curr) {
        visited[curr] = true;
        recStack[curr] = true;

        //int neighbor = preReqGraph[curr][0]; //for some cases, pre[curr] might not exist
        for (int neighbor: preReqGraph[curr]) {
            if (recStack[neighbor]) {
                return true;
            } else if (!visited[neighbor]) {
                if (DFS(preReqGraph, visited, recStack, neighbor)) {
                    return true;
                }
            }
        }

        recStack[curr] = false;
        return false;
    }

    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        std::vector<std::vector<int>> preReqGraph(numCourses);

        for (auto& prerequisite : prerequisites) {
            const int u = prerequisite[1];
            const int v = prerequisite[0];
            preReqGraph[u].push_back(v);
            //directed edge pre[i][1] -> pre[i][0]
        }

        std::vector<bool> visited(numCourses, false);
        std::vector<bool> recStack(numCourses, false);

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (DFS(preReqGraph, visited, recStack, i)) {
                    return false;    //Cycle detected -> cannot finish all courses
                }
            }
        }
        return true;    //No cycle found
    }

    void solution() {
        std::vector<std::vector<int>> prerequisites = {{1, 0}};
        int numCourses = 2;
        bool ans = canFinish(numCourses, prerequisites);
        std::cout << "Can the courses be finished?: " << ans << std::endl;
    }
};


#endif //LEETCODE_COURSESCHEDULE_H
