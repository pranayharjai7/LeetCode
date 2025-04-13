#ifndef LEETCODE_COMBINATIONSUM_H
#define LEETCODE_COMBINATIONSUM_H


#include <vector>
#include <iostream>
#include <set>

class CombinationSum {
public:

    void combSumRec(std::vector<int>& nums, int idx, std::vector<int> &combine,
                    std::set<std::vector<int>> &s, int target) {

        if (idx == nums.size()) {
            return;
        }
        if (target < 0) {
            return;
        }
        if (target == 0) {
            s.insert(combine);
            return;
        }

        combine.push_back(nums[idx]);
        combSumRec(nums, idx+1, combine, s, target-nums[idx]); //1. single inclusion
        combSumRec(nums, idx, combine, s, target-nums[idx]);  //2. multiple inclusion (index remains same)

        combine.pop_back();     //backtracking step
        combSumRec(nums, idx+1, combine, s, target);    //3. exclusion step
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::set<std::vector<int>> s;
        std::vector<int> combine;
        combSumRec(candidates, 0, combine, s, target);
        std::vector<std::vector<int>> ans (s.begin(), s.end());
        return ans;
    }

    void solution() {
        std::vector<int> candidates = {2,3,5};
        int target = 8;
        auto ans = combinationSum(candidates, target);
        std::cout << "Combinations from array who's sum is  " << target<< ": \n";
        for (auto &a: ans) {
            std::cout << "{";
            for (auto &i: a) {
                std::cout << i << " ";
            }
            std::cout << "}\n";
        }
    }
};


#endif //LEETCODE_COMBINATIONSUM_H
