#ifndef LEETCODE_PRACTICE2_H
#define LEETCODE_PRACTICE2_H

#include <vector>
#include "Graphs.h"

class Practice2 {
public:
    void printAllPaths(std::vector<std::vector<Edge>> &graph, std::vector<bool> &visited,
                  int curr, std::string path, int target) {
        if (curr == target) {
            std::cout << path << std::endl;
            return;
        }

        for (int i = 0; i < graph[curr].size(); ++i) {
            Edge e = graph[curr][i];
            if (!visited[e.dest]) {
                visited[curr] = true;
                printAllPaths(graph, visited, e.dest,
                         path + std::to_string(e.dest), target);
                visited[curr] = false;
            }
        }

    }

    bool isCycleDFS(std::vector<std::vector<Edge>> &graph, std::vector<bool> &visited,
                 int curr, std::vector<bool> &recStack) {
        visited[curr] = true;
        recStack[curr] = true;

        for (int i = 0; i < graph[curr].size(); ++i) {
            Edge e = graph[curr][i];
            if (recStack[e.dest]) {
                return true;
            } else if (!visited[e.dest]) {
                if (isCycleDFS(graph, visited, e.dest, recStack)) {
                    return true;
                }
            }
        }

        recStack[curr] = false;
        return false;
    }

    //O(E+V)
    bool detectCycleDirected(std::vector<std::vector<Edge>> &graph, int vertices, int curr) {
        std::vector<bool> visited(vertices, false);
        std::vector<bool> recStack(vertices, false);

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                if (isCycleDFS(graph, visited, i, recStack)) {
                    return true;
                }
            }
        }
        return false;

    }

    struct Pair {
        int node;
        int dist;

        Pair(int _node, int _dist) : node(_node), dist(_dist) {}

        bool operator<(const Pair &_pair) const {
            return dist > _pair.dist;
        }
    };

    void dijkstraAlgorithm(std::vector<std::vector<Edge>> &graph, int vertices, int curr) {
        std::vector<bool> visited(vertices, false);
        std::vector<int> dist(vertices, INT_MAX);
        std::priority_queue<Pair> pq;
        dist[curr] = 0;
        pq.emplace(curr, dist[curr]);

        while (!pq.empty()) {
            Pair curr = pq.top();
            pq.pop();

            if (!visited[curr.node]) {
                visited[curr.node] = true;

                for (int i = 0; i < graph[curr.node].size(); ++i) {
                    Edge e = graph[curr.node][i];
                    if (dist[e.src] + e.weight < dist[e.dest]) {
                        dist[e.dest] = dist[e.src] + e.weight;

                        pq.emplace(e.dest, dist[e.dest]);
                    }
                }
            }
        }

        for (int i = 0; i < vertices; ++i) {
            std::cout << dist[i] << " ";
        }
        std::cout << std::endl;
    }

    void solution() {
        std::vector<std::vector<Edge>> undirectedGraph;
        std::vector<std::vector<Edge>> directedGraph;
        int vertices = 7;
        createUndirectedGraph(undirectedGraph, vertices);
        createDirectedGraph(directedGraph, vertices);
        std::vector<bool> visited(vertices, false);
        std::string path = std::to_string(0);
        printAllPaths(undirectedGraph, visited, 0, path, 5); //O(V^V);

        std::cout << std::endl << "Detect Cycle (directed DFS): " << detectCycleDirected(directedGraph, vertices, 0);
        //std::cout << std::endl << "Detect Cycle (undirected DFS): " << detectCycleUndirected(undirectedGraph, vertices, 0);
        std::cout << std::endl << "Dijkstra's: ";
        dijkstraAlgorithm(directedGraph, vertices, 0);
    }

    void createUndirectedGraph(std::vector<std::vector<Edge>> &undirectedGraph, int v) {
        undirectedGraph.resize(v);

        undirectedGraph[0].emplace_back(0, 1, 8);
        undirectedGraph[0].emplace_back(0, 4, 4);

        undirectedGraph[1].emplace_back(1, 0, 8);
        undirectedGraph[1].emplace_back(1, 2, 4);
        undirectedGraph[1].emplace_back(1, 3, 2);
        undirectedGraph[1].emplace_back(1, 4, 1);

        undirectedGraph[2].emplace_back(2, 1, 4);
        undirectedGraph[2].emplace_back(2, 5, 2);

        undirectedGraph[3].emplace_back(3, 1, 2);
        undirectedGraph[3].emplace_back(3, 5, 3);
        undirectedGraph[3].emplace_back(3, 6, 4);

        undirectedGraph[4].emplace_back(4, 0, 4);
        undirectedGraph[4].emplace_back(4, 1, 1);
        undirectedGraph[4].emplace_back(4, 6, 2);

        undirectedGraph[5].emplace_back(5, 2, 2);
        undirectedGraph[5].emplace_back(5, 3, 3);
        undirectedGraph[5].emplace_back(5, 6, 3);

        undirectedGraph[6].emplace_back(6, 3, 4);
        undirectedGraph[6].emplace_back(6, 4, 2);
        undirectedGraph[6].emplace_back(6, 5, 3);
    }

    void createDirectedGraph(std::vector<std::vector<Edge>> &directedGraph, int v) {
        directedGraph.resize(v);

        directedGraph[0].emplace_back(0, 1, 8);
        directedGraph[0].emplace_back(0, 4, 4);

        directedGraph[1].emplace_back(1, 2, 4);
        directedGraph[1].emplace_back(1, 3, 2);

        directedGraph[2].emplace_back(2, 5, 2);

        directedGraph[3].emplace_back(3, 5, 3);
        directedGraph[3].emplace_back(3, 6, 4);

        directedGraph[4].emplace_back(4, 1, 1);

        directedGraph[5].emplace_back(5, 6, 3);

        directedGraph[6].emplace_back(6, 4, 2);
    }
};


#endif //LEETCODE_PRACTICE2_H
