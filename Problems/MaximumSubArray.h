#ifndef LEETCODE_MAXIMUMSUBARRAY_H
#define LEETCODE_MAXIMUMSUBARRAY_H


#include <vector>
#include <iostream>

class MaximumSubArray {
public:
    void printAllSubArrays(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                for (int k = i; k <= j; ++k) {
                    std::cout << nums[k];
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

    int maxSubArrayBruteForce(std::vector<int>& nums) {
        int maxSum = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); ++j) {
                int currSum = 0;
                for (int k = i; k <= j; ++k) {
                    currSum += nums[k];
                }
                maxSum = std::max(currSum, maxSum);
            }
        }
        return maxSum;
    }

    int maxSubArrayBruteForceOptimized(std::vector<int>& nums) {
        int maxSum = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int currSum = 0;
            for (int j = i; j < nums.size(); ++j) {
                currSum += nums[j];
                maxSum = std::max(currSum, maxSum);
            }
        }
        return maxSum;
    }

    int maxSubArrayKadaneAlgorithm(std::vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for (int num : nums) {
            currSum+=num;
            maxSum = std::max(currSum, maxSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }

    void solution() {
        std::vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
        std::cout << "All SubArrays:" << std::endl;
        printAllSubArrays(vec);
        int maxSum = maxSubArrayBruteForce(vec);
        std::cout << "Maximum SubArray Sum Brute Force: " << maxSum << std::endl;
        int maxSum2 = maxSubArrayBruteForceOptimized(vec);
        std::cout << "Maximum SubArray Sum Brute Force Optimized: " << maxSum2 << std::endl;
        int maxSum3 = maxSubArrayKadaneAlgorithm(vec);
        std::cout << "Maximum SubArray Kadane's Algorithm: " << maxSum3 << std::endl;
    }
};



#endif //LEETCODE_MAXIMUMSUBARRAY_H
