#ifndef LEETCODE_REACHTHEEND_H
#define LEETCODE_REACHTHEEND_H

#include <vector>
#include <queue>
#include <iostream>

/*
 * Given an array of integers, and you can jump to arr[arr[i]] from arr[i].
 * Find the minimum cost to reach n-1.
 */
class ReachTheEnd {
public:
    int minCostToReachTheEnd(std::vector<int> &arr) {
        std::vector<bool> visited(arr.size(), false);

        int idx = 0;
        int cost = 0;
        visited[0] = true;
        while (idx != arr.size() - 1) {
            if (0 <= idx && idx <= arr.size() - 1) {
                if (!visited[arr[idx]]) {
                    visited[arr[idx]] = true;
                    idx = arr[idx];
                    cost++;
                } else {
                    //infinite loop
                    return -1;
                }
            } else {
                //out of bounds
                return -1;
            }
        }

        return cost;
    }

    void solution() {
        std::vector<int> arr = {2, 0, 3, 5, 4, 6};
        int ans = minCostToReachTheEnd(arr);
        std::cout << "Minimum cost to reach end by hopping: " << ans << std::endl;
    }
};


#endif //LEETCODE_REACHTHEEND_H
