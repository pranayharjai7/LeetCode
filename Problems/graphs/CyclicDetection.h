#ifndef LEETCODE_CYCLICDETECTION_H
#define LEETCODE_CYCLICDETECTION_H


#include <vector>
#include "Graphs.h"

class CyclicDetection {
public:
    bool detectCycleInGraph(std::vector<std::vector<Edge>> &graph, std::vector<bool> &visited,
                            std::vector<bool> &recursionStack, int curr) {
        visited[curr] = true;
        recursionStack[curr] = true;

        for (int i = 0; i < graph[curr].size(); ++i) {  //loop for all neighbors
            Edge e = graph[curr][i];
            if (recursionStack[e.dest]) { //cycle condition
                return true;
            } else if (!visited[e.dest]) {
                if (detectCycleInGraph(graph, visited, recursionStack, e.dest)) {
                    return true;
                }
            }
        }

        recursionStack[curr] = false;
        return false;
    }

    bool isCycleUndirected(std::vector<std::vector<Edge>> &graph, std::vector<bool> &visited,
                           int curr, int parent) {
        visited[curr] = true;

        for (int i = 0; i < graph[curr].size(); ++i) {
            Edge e = graph[curr][i];
            if (visited[e.dest] && parent != e.dest) {
                return true;
            } else if (!visited[e.dest]) {
                if (isCycleUndirected(graph, visited, e.dest, curr)) {
                    return true;
                }
            }
        }

        return false;
    }

    void createDirectedGraph(std::vector<std::vector<Edge>> &graph, int vertices) {
        graph.resize(vertices);

        graph[0].emplace_back(0,2,1);
        graph[1].emplace_back(1,0,1);
        graph[2].emplace_back(2,3,1);
        graph[3].emplace_back(3,0,1);
    }

    void createUndirectedGraph(std::vector<std::vector<Edge>> &graph, int vertices) {
        graph.resize(vertices);

        graph[0].emplace_back(0,1,1);
        graph[0].emplace_back(0,4,1);
        graph[1].emplace_back(1,0,1);
        graph[1].emplace_back(1,2,1);
        graph[1].emplace_back(1,4,1);
        graph[2].emplace_back(2,1,1);
        graph[2].emplace_back(2,3,1);
        graph[3].emplace_back(3,2,1);
        graph[4].emplace_back(4,0,1);
        graph[4].emplace_back(4,1,1);
        graph[4].emplace_back(4,5,1);
        graph[5].emplace_back(5,4,1);
    }

    void solution() {
        std::vector<std::vector<Edge>> graph;
        int vertices = 4;
        createDirectedGraph(graph, vertices);
        std::vector<bool> visited(vertices, false);
        std::vector<bool> recursionStack(vertices, false);
        bool ans = detectCycleInGraph(graph, visited, recursionStack, 0);
        std::cout << "Is directed graph cyclic?: " << ans << std::endl;

        std::vector<std::vector<Edge>> graph2;
        int vertices2 = 6;
        createUndirectedGraph(graph2, vertices2);
        std::vector<bool> visited2(vertices2, false);
        bool ans2 = isCycleUndirected(graph2, visited2, 0, -1);
        std::cout << "Is undirected graph cyclic?: " << ans2 << std::endl;
        //TC same as DFS O(E+V)
    }
};


#endif //LEETCODE_CYCLICDETECTION_H
