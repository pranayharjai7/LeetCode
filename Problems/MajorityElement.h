#ifndef LEETCODE_MAJORITYELEMENT_H
#define LEETCODE_MAJORITYELEMENT_H


#include <vector>
#include <iostream>
#include <algorithm>

class MajorityElement {
public:
    int majorityElementBruteForce(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int freq = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[i] == nums[j]) {
                    freq++;
                }
                if (freq > n/2) {
                    return nums[i];
                }
            }
        }
        return -1;
    }

    int majorityElementBruteForceOptimized(std::vector<int>& nums) {
        int n= nums.size();
        std::sort(nums.begin(), nums.end());
        int ans = nums[0];
        int freq = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == ans) {
                freq++;
            } else {
                ans = nums[i];
                freq = 1;
            }
            if (freq > n/2) {
                return ans;
            }
        }
        return ans;
    }

    int majorityElementMooreAlgorithm(std::vector<int>& nums) {
        int n = nums.size();
        int ans  = nums[0];
        int freq = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == ans) {
                freq++;
            } else {
                freq--;
            }
            if (freq == 0) {
                ans = nums[i];
                freq = 1;
            }
        }
        return ans;
    }

    void solution() {
        std::vector<int> nums = {2,2,1,1,1,2,2};
        int mj = majorityElementBruteForce(nums);
        std::cout<< "Majority Element with Brute force: " << mj << std::endl;
        int mj2 = majorityElementBruteForceOptimized(nums);
        std::cout<< "Majority Element with Brute force Optimized: " << mj2 << std::endl;
        int mj3 = majorityElementMooreAlgorithm(nums);
        std::cout<< "Majority Element with Moore's Algorithm: " << mj3 << std::endl;
    }
};


#endif //LEETCODE_MAJORITYELEMENT_H
