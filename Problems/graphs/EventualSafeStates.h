#ifndef LEETCODE_EVENTUALSAFESTATES_H
#define LEETCODE_EVENTUALSAFESTATES_H

#include <vector>
#include <iostream>

class EventualSafeStates {
public:
    bool isCycleDetected(std::vector<std::vector<int>> &graph, std::vector<bool> &visited, int curr,
                         std::vector<bool> &recStack, std::vector<bool> &safe) {
        visited[curr] = true;
        recStack[curr] = true;

        for (int i = 0; i < graph[curr].size(); ++i) {
            auto dest = graph[curr][i];
            if (recStack[dest]) {
                return true;   //cycle found
            } else if (!visited[dest]) {
                if (isCycleDetected(graph, visited, dest, recStack, safe)) {
                    return true;
                }
            } else if (!safe[dest]) {
                //already visited but not safe. leads to cycle
                return true;
            }
        }

        recStack[curr] = false;
        safe[curr] = true;
        return false;
    }

    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>> &graph) {
        std::vector<bool> visited(graph.size(), false);
        std::vector<bool> recursionStack(graph.size(), false);
        std::vector<bool> safe(graph.size(), false);


        for (int i = 0; i < graph.size(); ++i) {
            if (!visited[i]) {
                isCycleDetected(graph, visited, i, recursionStack, safe);
            }
        }

        std::vector<int> ans;
        for (int i = 0; i < graph.size(); ++i) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    void solution() {
        std::vector<std::vector<int>> graph = {{1, 2},
                                               {2, 3},
                                               {5},
                                               {0},
                                               {5},
                                               {},
                                               {}};

        auto ans = eventualSafeNodes(graph);
        std::cout << "Eventual safe states in graph: ";
        for (auto &x: ans) {
            std::cout << x << ", ";
        }
    }
};


#endif //LEETCODE_EVENTUALSAFESTATES_H
