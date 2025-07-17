#ifndef VECTORREVISION_H
#define VECTORREVISION_H

#include <iostream>
#include <vector>

class VectorRevision {
public:
    int singleNumber(std::vector<int> &nums) {
        int ans = 0;
        for (const auto &i: nums) {
            ans ^= i;
        }

        return ans;
    }

    //Maximum subarray sum
    int kadanesAlgorithm(std::vector<int> &nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            currSum += nums[i];
            maxSum = std::max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    }

    //Majority Element
    int mooresAlgorithm(std::vector<int> &nums) {
        int ans = nums[0];
        int freq = 1;
        for (int i = 1; i < nums.size(); ++i) {
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
        std::vector<int> vec = {1, 2, -8, -1, 3, 3, 2, 12, 1, -1, -8};
        std::cout << vec.size() << std::endl;

        std::cout << "Single number in Array: " << singleNumber(vec) << std::endl;
        std::cout << "Maximum subarray sum: " << kadanesAlgorithm(vec) << std::endl;
    }
};


#endif //VECTORREVISION_H
