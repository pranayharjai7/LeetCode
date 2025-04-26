#ifndef LEETCODE_GRAPHS_H
#define LEETCODE_GRAPHS_H

#include <vector>
#include <iostream>
#include <queue>
#include <stack>

struct Edge {
    int src;
    int dest;
    int weight;

    Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}
};


class Graphs {
private:

public:

    void createGraph(std::vector<std::vector<Edge>> &adjList, int v) {
        adjList.resize(v);

//        Edge e(0,2);
//        adjList[0].push_back(e);
        adjList[0].emplace_back(0, 1, 10);
        adjList[0].emplace_back(0, 2, 2);

        adjList[1].emplace_back(1, 0, 10);
        adjList[1].emplace_back(1, 3, 0);

        adjList[2].emplace_back(2, 0, 2);
        adjList[2].emplace_back(2, 4, 10);

        adjList[3].emplace_back(3, 1, 0);
        adjList[3].emplace_back(3, 4, 1);
        adjList[3].emplace_back(3, 5, 1);

        adjList[4].emplace_back(4, 2, 10);
        adjList[4].emplace_back(4, 3, 1);
        adjList[4].emplace_back(4, 5, 1);

        adjList[5].emplace_back(5, 3, 1);
        adjList[5].emplace_back(5, 4, 1);
        adjList[5].emplace_back(5, 6, 1);

        adjList[6].emplace_back(6, 5, 1);
    }

    void printNeighbors(std::vector<std::vector<Edge>> &adjList, int vertex) {
        for (int i = 0; i < adjList[vertex].size(); ++i) {
            std::cout << adjList[vertex][i].dest << " ";
        }
    }

    void breadthFirstTraversal(std::vector<std::vector<Edge>> &adjList, int v) {
        std::vector<bool> visited(v, false);
        std::queue<int> q;
        for (int i = 0; i < v; ++i) { // to tackle disjoint graphs
            if (!visited[i]) {
                q.push(adjList[i][0].src);
            }

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                if (!visited[curr]) {
                    std::cout << curr << " ";
                    visited[curr] = true;

                    //add neighbors
                    for (int j = 0; j < adjList[curr].size(); ++j) {
                        q.push(adjList[curr][j].dest);
                    }
                }
            }
        }
    }

    void depthFirstTraversalRecursive(std::vector<std::vector<Edge>> &adjList,
                                      std::vector<bool> &visited, int curr) {
        std::cout << curr << " ";
        visited[curr] = true;
        for (int i = 0; i < adjList[curr].size(); ++i) {
            Edge e = adjList[curr][i];
            if (!visited[e.dest]) {
                depthFirstTraversalRecursive(adjList, visited, e.dest);
            }
        }
    }

    void solution() {
        std::cout << "Graphs: \n";
        /*
         *      1---3
         *    /     | \
         *   0      |  5--6
         *    \     | /
         *      2---4
         */
        std::vector<std::vector<Edge>> adjList;
        int noOfVertices = 7;
        createGraph(adjList, noOfVertices);
        std::cout << "Neighbors of vertex 2: ";
        printNeighbors(adjList, 2);
        std::cout << std::endl << "Breadth First Traversal: ";
        breadthFirstTraversal(adjList, noOfVertices);
        std::cout << std::endl << "Depth First Traversal: ";
        std::vector<bool> visited(noOfVertices, false);
        for (int i = 0; i < noOfVertices; ++i) { // to tackle disjoint graphs
            if (!visited[i]) {
                depthFirstTraversalRecursive(adjList, visited, adjList[i][0].src);
            }
        }
        std::cout << std::endl;
    }
};


#endif //LEETCODE_GRAPHS_H
