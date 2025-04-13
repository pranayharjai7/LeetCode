#ifndef LEETCODE_PRACTICE_H
#define LEETCODE_PRACTICE_H

#include <iostream>
#include <vector>
#include <queue>
#include "Graphs.h"

class Practice {
public:
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

    void BFS(std::vector<std::vector<Edge>> &graph, int v, int src) {
        std::vector<bool> visited(v, false);

        for (int i = 0; i < v; ++i) {   //to tackle disjoint graphs
            if (!visited[i]) {
                std::queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    if (!visited[curr]) {
                        std::cout << curr << " ";
                        visited[curr] = true;

                        for (int j = 0; j < graph[curr].size(); ++j) {
                            Edge e = graph[curr][j];
                            q.push(e.dest);
                        }
                    }
                }
            }
        }
    }

    void DFSRec(std::vector<std::vector<Edge>> &graph, std::vector<bool> &visited, int curr) {
        if (visited[curr]) return;
        std::cout << curr << " ";
        visited[curr] = true;

        for (int i = 0; i < graph[curr].size(); ++i) {
            Edge e = graph[curr][i];
            DFSRec(graph, visited, e.dest);
        }
    }

    void DFS(std::vector<std::vector<Edge>> &graph, int v, int src) {
        std::vector<bool> visited(v, false);

        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {
                DFSRec(graph, visited, i);
            }
        }
    }

    bool detectCycleDirectedDFS(std::vector<std::vector<Edge>> &graph, std::vector<bool> &visited, std::vector<bool> recStack, int curr) {
        visited[curr] = true;
        recStack[curr] = true;

        for (int i = 0; i < graph[curr].size(); ++i) {
            Edge e = graph[curr][i];
            if (recStack[e.dest]) {
                return true;
            }
            if (!visited[e.dest]) {
                if (detectCycleDirectedDFS(graph, visited, recStack, e.dest)) {
                    return true;
                }
            }
        }

        recStack[curr] = false;
        return false;
    }

    bool detectCycleDirected(std::vector<std::vector<Edge>> &graph, const int v, int src) {
        std::vector<bool> visited(v, false);
        std::vector<bool> recStack(v, false);
        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {
                if (detectCycleDirectedDFS(graph, visited, recStack, i)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool
    detectCycleUndirectedDFS(std::vector<std::vector<Edge>> &graph, std::vector<bool> &visited, int curr, int parent) {
        visited[curr] = true;

        for (int i = 0; i < graph[curr].size(); ++i) {
            Edge e = graph[curr][i];
            if (visited[e.dest] && e.dest != parent) {
                return true;
            }
            if (!visited[e.dest]) {
                if (detectCycleUndirectedDFS(graph, visited, e.dest, curr)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool detectCycleUndirected(std::vector<std::vector<Edge>> &graph, const int v, int src) {
        std::vector<bool> visited(v, false);
        return detectCycleUndirectedDFS(graph, visited, src, -1);
    }

    struct Pair {
        int node;
        int dist;
        Pair(int node, int dist): node(node), dist(dist) {}
        bool operator<(const Pair &p) const {
            return dist > p.dist;
        }
    };
    void dijkstraAlgorithm(std::vector<std::vector<Edge>>& graph, int v, int src) {
        std::vector<bool> visited(v, false);
        std::vector<int> distance(v, INT_MAX);
        distance[src] = 0;

        std::priority_queue<Pair> pq;
        pq.emplace(src, 0);

        while (!pq.empty()) {
            Pair curr = pq.top();
            pq.pop();

            if (!visited[curr.node]) {
                std::cout << curr.node << " ";
                visited[curr.node] = true;

                for (int i = 0; i < graph[curr.node].size(); ++i) {
                    Edge e = graph[curr.node][i];
                    if (distance[e.src] + e.weight < distance[e.dest]) {
                        distance[e.dest] = distance[e.src] + e.weight;
                        pq.emplace(e.dest, distance[e.dest]);
                    }
                }
            }
        }
    }


    void solution() {
        std::vector<std::vector<Edge>> undirectedGraph;
        std::vector<std::vector<Edge>> directedGraph;
        const int vertices = 7;

        createUndirectedGraph(undirectedGraph, vertices);
        createDirectedGraph(directedGraph, vertices);

        std::cout << "---------------";
        std::cout << std::endl << "Print all neighbors (undirected BFS) \n";
        BFS(undirectedGraph, vertices, 0);
        std::cout << std::endl << "Print all neighbors (directed BFS) \n";
        BFS(directedGraph, vertices, 0);
        std::cout << std::endl << "Print all neighbors (undirected DFS) \n";
        DFS(undirectedGraph, vertices, 0);
        std::cout << std::endl << "Print all neighbors (directed DFS) \n";
        DFS(directedGraph, vertices, 0);
        std::cout << std::endl << "Detect Cycle (undirected DFS): " << detectCycleUndirected(directedGraph, vertices, 0);
        std::cout << std::endl << "Detect Cycle (directed DFS): " << detectCycleDirected(directedGraph, vertices, 0);
        std::cout << std::endl << "dijkstra's Algorithm (undirected BFS): \n";
        dijkstraAlgorithm(undirectedGraph, vertices, 0);
        std::cout << std::endl << "dijkstra's Algorithm (directed BFS): \n";
        dijkstraAlgorithm(directedGraph, vertices, 0);

    }
};


#endif //LEETCODE_PRACTICE_H
