#ifndef LEETCODE_CHEAPESTFLIGHTSWITHKSTOPS_H
#define LEETCODE_CHEAPESTFLIGHTSWITHKSTOPS_H

class CheapestFlightsWithKStops {
public:

    std::vector<std::vector<Edge>> convertFlightToGraph(std::vector<std::vector<int>> &flights, int n) {
        std::vector<std::vector<Edge>> graph(n);
        for (int i = 0; i < flights.size(); ++i) {
            graph[flights[i][0]].emplace_back(flights[i][0], flights[i][1], flights[i][2]);
        }

        return graph;
    }

    int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src, int dst, int k) {

        auto graph = convertFlightToGraph(flights, n);
        std::vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i < k + 1; ++i) {
            std::vector<int> tempDist(dist);

            for (int j = 0; j < n; ++j) {
                for (int l = 0; l < graph[j].size(); ++l) {
                    Edge e = graph[j][l];
                    if (dist[e.src] != INT_MAX) {
                        if (dist[e.src] + e.weight < tempDist[e.dest]) {
                            tempDist[e.dest] = dist[e.src] + e.weight;
                        }
                    }
                }
            }
            dist = tempDist;
        }
        if (dist[dst] != INT_MAX) {
            return dist[dst];
        } else {
            return -1;
        }
    }

    void solution() {
        std::vector<std::vector<int>> graph = {{0, 1, 100},
                                               {1, 2, 100},
                                               {2, 0, 100},
                                               {1, 3, 600},
                                               {2, 3, 200}};
        int vertices = 4;
        int k = 1;
        int cheapestPrice = findCheapestPrice(vertices, graph, 0, 3, k);
        std::cout << "Cheapest Flight With " << k << " Stops: " << cheapestPrice << std::endl;
    }
};


#endif //LEETCODE_CHEAPESTFLIGHTSWITHKSTOPS_H
