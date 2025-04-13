//
// Created by harjai on 20-Mar-25.
//

#ifndef LEETCODE_BELLMANFORDALGORITHM_H
#define LEETCODE_BELLMANFORDALGORITHM_H


#include <vector>
#include "Graphs.h"

class BellmanFordAlgorithm {
public:

    void bellmanFord(std::vector<std::vector<Edge>> &graph, int src, int vertices) {
        std::vector<int> dist(vertices, INT_MAX);
        dist[src] = 0;


        for (int i = 0; i < vertices-1; ++i) {  // loop should run as much as there are vertices
            for (int j = 0; j < vertices; ++j) {    //loop through vertices
                for (int k = 0; k < graph[j].size(); ++k) { //neighbors of each vertex
                    Edge e = graph[j][k];

                    if (dist[e.src] != INT_MAX) {
                        if (dist[e.src] + e.weight < dist[e.dest]) {
                            dist[e.dest] = dist[e.src] + e.weight;
                        }
                    }
                }
            }
        }

        //Negative weight cycle:
        //check if after another loop, still there is a change or decrease in distance..
        for (int j = 0; j < vertices; ++j) {    //loop through vertices
            for (int k = 0; k < graph[j].size(); ++k) { //neighbors of each vertex
                Edge e = graph[j][k];

                if (dist[e.src] != INT_MAX) {
                    if (dist[e.src] + e.weight < dist[e.dest]) {
                        std::cout << " Negative weight cycle\n";
                    }
                }
            }
        }

        //Print all distances
        for (int i = 0; i < dist.size(); ++i) {
            std::cout << dist[i] << " ";
        }
    }

    void createGraph(std::vector<std::vector<Edge>> &graph, int v) {
        graph.resize(v);

        graph[0].emplace_back(0,1,2);
        graph[0].emplace_back(0,2,4);
        graph[1].emplace_back(1,2,-4);
        graph[2].emplace_back(2,3,2);
        graph[3].emplace_back(3,4,4);
        graph[4].emplace_back(4,1,-1);
    }

    void solution() {
        std::vector<std::vector<Edge>> graph;
        int noOfVertices = 5;
        createGraph(graph, noOfVertices);
        std::cout << "Bellman-Ford Algorithm, Shortest paths from 0:";
        bellmanFord(graph, 0, noOfVertices);
        //O(E*V)
        //E => no. of edges traversed
        std::cout << std::endl;
    }
};


#endif //LEETCODE_BELLMANFORDALGORITHM_H
