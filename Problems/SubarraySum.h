#ifndef LEETCODE_SUBARRAYSUM_H
#define LEETCODE_SUBARRAYSUM_H


#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

class SubarraySum {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            int currSum = 0;
            for (int j = i; j < nums.size(); ++j) {
                currSum += nums[j];
                if (currSum == k) {
                    count++;
                }
            }
        }
        return count;
    }

    int subarraySumWithPrefixSum(std::vector<int>& nums, int k) {
        int count = 0;
        std::vector<int> prefixSum(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            prefixSum[i] = sum;
        }
        // sub array sum from i->j = prefixSum[j]-prefixSum[i-1];
        // k == prefixSum[j]-prefixSum[i-1]
        // prefixSum[j] - k = prefixSum[i-1]

        std::unordered_map<int, int> uMap;  //stores prefixSum, its frequency
        for (int j = 0; j < nums.size(); ++j) {
            if (prefixSum[j] == k) count++;
            int compliment = prefixSum[j] - k;
            if (uMap.find(compliment) != uMap.end()) {
                count += uMap[compliment];  //add the frequency of compliment (1 if it exists 1 time.. 2 if twice)
            }
            if (uMap.find(prefixSum[j]) == uMap.end()) {
                uMap[prefixSum[j]] = 0;
            }
            uMap[prefixSum[j]]++;
        }
        return count;
    }

    void solution() {
        std::vector<int> nums = {1,2,3};
        int k = 3;

        int count = subarraySum(nums, k);
        std::cout << "Subarray Sum equals K count: " << count << std::endl;

        int count2 = subarraySumWithPrefixSum(nums, k);
        std::cout << "Subarray Sum equals K count Optimized with Prefix Sum: " << count2 << std::endl;
    }
};


#endif //LEETCODE_SUBARRAYSUM_H
