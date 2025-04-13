#ifndef LEETCODE_ALLPATHSGRAPH_H
#define LEETCODE_ALLPATHSGRAPH_H

#include "Graphs.h"

class AllPathsGraph : public Graphs {
public:
    void depthFirstTraversalRecursive(std::vector<std::vector<Edge>> &adjList,
                                      std::vector<bool> &visited, int curr,
                                      std::string path, int target) {
        if (curr == target) {
            std::cout << path << std::endl;
            return;
        }

        for (int i = 0; i < adjList[curr].size(); ++i) {
            Edge e = adjList[curr][i];
            if (!visited[e.dest]) {
                visited[curr] = true;
                depthFirstTraversalRecursive(adjList, visited, e.dest,
                                             path+std::to_string(e.dest), target);
                visited[curr] = false;
            }
        }

    }

    void solution() {
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

        std::cout << "All paths from src to target: \n";
        //Paths can only be found using DFS
        int src = 0;
        int target = 5;
        std::vector<bool> visited(noOfVertices, false);
        depthFirstTraversalRecursive(adjList, visited, src,
                                     std::to_string(src), target);
    }
};


#endif //LEETCODE_ALLPATHSGRAPH_H
