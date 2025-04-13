//
// Created by harjai on 26-Feb-25.
//

#ifndef LEETCODE_TWOSUM_H
#define LEETCODE_TWOSUM_H


#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

class TwoSum {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::vector<int> ans;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if ((nums.at(i) + nums.at(j)) == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return {};
    }


    std::vector<int> twoSumOptimized(std::vector<int> nums, int target) {
        std::vector<int> temp = nums;
        std::sort(nums.begin(), nums.end());    //nLogn
        std::vector<int> ans;
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {                           //O(n)
            int sum = nums[start] + nums[end];
            if (sum == target) {
                break;
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }
        if (start < end) {
            int count = 0;
            for (int i = 0; i < temp.size(); ++i) {
                if (count == 2) break;
                if (nums[start] == temp[i] || nums[end] == temp[i]) {
                    ans.push_back(i);
                    count++;
                }
            }
        }
        return ans;
    }


    std::vector<int> twoSumMap(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> uMap;
        for (int i = 0; i < nums.size(); ++i) {
            int first = nums[i];
            int second = target - first;
            if (uMap.find(second) != uMap.end()) { //map because searching in a map is O(1).
                return {i, uMap[second]};
            }
            uMap.insert({nums[i],i}); // or uMap[first] = i;
        }
        return {};
    }

    void solution() {
        std::vector<int> x = {5, 2, 11, 7, 15};
        std::vector<int> ans = twoSum(x, 9);
        std::cout << "Two Sum for the target found at {O(n^2)}: " << ans.at(0) << ", " << ans.at(1) << std::endl;

        std::vector<int> ans2 = twoSumOptimized(x, 9);
        std::cout << "Two Sum Optimized {O(nlogn)}: " << ans2.at(0) << ", " << ans2.at(1) << std::endl;

        std::vector<int> ans3 = twoSumMap(x, 9);
        std::cout << "Two Sum Optimized {O(n)}: " << ans3.at(0) << ", " << ans3.at(1) << std::endl;
    }
};


#endif //LEETCODE_TWOSUM_H
