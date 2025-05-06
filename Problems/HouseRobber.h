#ifndef LEETCODE_HOUSEROBBER_H
#define LEETCODE_HOUSEROBBER_H


#include <vector>
#include <iostream>

class HouseRobber {
public:
    int robbed(std::vector<int> &nums, int curr, std::vector<int> &visited) {   //kind of DFS
        if (curr >= nums.size()) {
            return 0;
        }

        //if it has already been visited, it'll have the max answer stored in it
        if (visited[curr] != -1) {
            return visited[curr];
        }
        //if it has not been visited,
        //lets calculate the max answer possible with it and store it in visited[curr].

        //when I choose the current to be included
        int pick = nums[curr] + robbed(nums, curr + 2, visited);

        //when I choose the current not to be included
        int skip = robbed(nums, curr + 1, visited);

        visited[curr] = std::max(pick, skip);

        return visited[curr];
    }

    int rob(std::vector<int> &nums) {
        std::vector<int> visited(nums.size(), -1);
        return robbed(nums, 0, visited);
    }

    void solution() {
        std::vector<int> nums = {2, 7, 9, 3, 1};
        std::cout << "Maximum amount that can be robbed from houses: " << rob(nums) << std::endl;
    }
};


#endif //LEETCODE_HOUSEROBBER_H
