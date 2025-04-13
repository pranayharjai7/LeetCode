#ifndef LEETCODE_DIJKSTRAALGORITHM_H
#define LEETCODE_DIJKSTRAALGORITHM_H

#include <vector>
#include "Graphs.h"

struct Pair {
    int node;
    int dist;

    Pair(int node, int dist) : node(node), dist(dist) {}

    bool operator<(const Pair &other) const {
        return dist > other.dist;
    }
};

class DijkstraAlgorithm {
public:

    void dijkstra(std::vector<std::vector<Edge>> &graph, int src, int v) {
        std::priority_queue<Pair> pq;
        std::vector<int> dist(v, INT_MAX);
        std::vector<bool> visited(v, false);

        pq.emplace(0, 0);
        dist[src] = 0;

        //BFS
        while (!pq.empty()) {
            Pair curr = pq.top();
            pq.pop();
            if (visited[curr.node]) continue;
            visited[curr.node] = true;
            for (int i = 0; i < graph[curr.node].size(); ++i) {
                Edge e = graph[curr.node][i];
                if (dist[e.src] + e.weight < dist[e.dest]) {
                    dist[e.dest] = dist[e.src] + e.weight;
                    pq.emplace(e.dest, dist[e.dest]);
                }
            }
        }

        //printing all Distances:
        for (int i = 0; i < v; ++i) {
            std::cout << dist[i] << " ";
        }
    }

    void createGraph(std::vector<std::vector<Edge>> &graph, int v) {
        graph.resize(v);

        graph[0].emplace_back(0, 1, 2);
        graph[0].emplace_back(0, 2, 4);
        graph[1].emplace_back(1, 3, 7);
        graph[1].emplace_back(1, 2, 1);
        graph[2].emplace_back(2, 4, 3);
        graph[3].emplace_back(3, 5, 1);
        graph[4].emplace_back(4, 3, 2);
        graph[4].emplace_back(4, 5, 5);
    }

    void solution() {
        std::vector<std::vector<Edge>> graph;
        int noOfVertices = 6;
        createGraph(graph, noOfVertices);
        std::cout << "Dikjstra's Algorithm, Shortest paths from 0:";
        dijkstra(graph, 0, noOfVertices);
        //O(E + ElogV)
        // ElogV => because of priority queue, nlogn for sorting..
        //E => no. of edges traversed
        std::cout << std::endl;
    }
};


#endif //LEETCODE_DIJKSTRAALGORITHM_H
