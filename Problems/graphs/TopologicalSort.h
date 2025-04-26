#ifndef LEETCODE_TOPOLOGICALSORT_H
#define LEETCODE_TOPOLOGICALSORT_H

#include <vector>
#include "Graphs.h"

/*
 * ONLY FOR DAG: Directed Acyclic Graphs
 * Topological sorting is writing all the vertices in linear order based on dependency.
 * E.G.
 * A --> B
 *   \   |
 *    \  |
 *       C --> D
 *
 * output: A, B, C, D
 * This is the topological-sorted order
 * Topological sort shows dependency of one Vertex on the other.
 * Here, C is always depended on B or A. C cannot be reached without A and C.
 * There can be multiple outputs.
*/
class TopologicalSort {


public:
    void DFS(std::vector<std::vector<Edge>> &graph, std::vector<bool> &visited,
             std::stack<int> &stack, int curr) {
        visited[curr] = true;

        for (int i = 0; i < graph[curr].size(); ++i) {
            Edge e = graph[curr][i];
            if (!visited[e.dest]) {
                DFS(graph, visited, stack, e.dest);
            }
        }
        stack.push(curr);   // this is the only difference from original DFS
    }

    void topologicalSort(std::vector<std::vector<Edge>> &graph, int vertices) {
        std::vector<bool> visited(vertices, false);
        std::stack<int> stack;
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                DFS(graph, visited, stack, i);
            }
        }

        while (!stack.empty()) {
            std::cout << stack.top() << " ";
            stack.pop();
        }
    }

    void createGraph(std::vector<std::vector<Edge>> &graph, int vertices) {
        graph.resize(vertices);

        graph[2].emplace_back(2, 3, 1);

        graph[3].emplace_back(3, 1, 1);

        graph[4].emplace_back(4, 0, 1);
        graph[4].emplace_back(4, 1, 1);

        graph[5].emplace_back(5, 0, 1);
        graph[5].emplace_back(5, 2, 1);
    }

    void solution() {
        std::vector<std::vector<Edge>> graph;
        int vertices = 6;
        createGraph(graph, vertices);
        std::cout << "Topological Sorted graph: ";
        topologicalSort(graph, vertices);
        std::cout << std::endl;
    }
};


#endif //LEETCODE_TOPOLOGICALSORT_H
