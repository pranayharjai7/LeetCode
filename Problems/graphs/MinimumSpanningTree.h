#ifndef LEETCODE_MINIMUMSPANNINGTREE_H
#define LEETCODE_MINIMUMSPANNINGTREE_H


#include <vector>
#include "Graphs.h"

class MinimumSpanningTree {
public:

    struct Pair {
        int node;
        int cost;

        Pair(int node, int cost): node(node), cost(cost) {};

        bool operator<(const Pair &other) const {
            return cost > other.cost;
        }
    };

    void primsAlgorithm(std::vector<std::vector<Edge>> &graph, int v) {
        std::vector<bool> visited(v, false);    //MST set
        std::priority_queue<Pair> pq;                    //Non-MST set
        pq.emplace(0,0);

        int mstCost = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            if (!visited[curr.node]) {
                visited[curr.node] = true;
                mstCost += curr.cost;

                for (int i = 0; i < graph[curr.node].size(); ++i) {
                    Edge e = graph[curr.node][i];
                    if (!visited[e.dest]) {
                        pq.emplace(e.dest, e.weight);
                    }
                }
            }
        }

        std::cout << "MST cost: " << mstCost << std::endl;
    }

    void createGraph(std::vector<std::vector<Edge>> &graph, int v) {
        graph.resize(v);

        graph[0].emplace_back(0, 1, 10);
        graph[0].emplace_back(0, 2, 15);
        graph[0].emplace_back(0, 3, 30);

        graph[1].emplace_back(1, 0, 10);
        graph[1].emplace_back(1, 3, 40);

        graph[2].emplace_back(2, 0, 15);
        graph[2].emplace_back(2, 3, 50);

        graph[3].emplace_back(3, 1, 40);
        graph[3].emplace_back(3, 2, 50);
    }

    void solution() {
        std::vector<std::vector<Edge>> graph;
        int v = 4;
        createGraph(graph, v);
        primsAlgorithm(graph, v);
        //O(ElogE)
        // because worst case is that each of the edges are added in priority queue, and sorting in
        // priority queue will be ElogE.
    }
};


#endif //LEETCODE_MINIMUMSPANNINGTREE_H
