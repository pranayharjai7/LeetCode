#ifndef LEETCODE_THREESUM_H
#define LEETCODE_THREESUM_H


#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

class ThreeSum {
public:

    //return triplets where sum of 3 should be 0
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        int n = nums.size();                    //2D vector does not store unique triplets.
        std::set<std::vector<int>> set;         // we are using set to store unique triplets.
        // we are using sets instead of unordered_set
        // because set provides hashing
        // in unordered_set, we need to provide our own hashing.
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        std::vector<int> triplet = {nums[i], nums[j], nums[k]};
                        std::sort(triplet.begin(), triplet.end());      //sorting so that each triplet is unique in set
                        set.insert(triplet);        //duplicate value would not be inserted in a set.
                    }
                }
            }
        }

        std::vector<std::vector<int>> ans(set.begin(), set.end());
        return ans;
    }

    //a+b+c = 0;
    //=> c = -a-b;
    std::vector<std::vector<int>> threeSumOptimized(std::vector<int> &nums) {
        int n = nums.size();
        std::set<std::vector<int>> uniquetriplets;

        for (int i = 0; i < n; ++i) {
            std::set<int> tempSet;
            for (int j = i + 1; j < n; ++j) {
                int c = -nums[i] - nums[j];                  //c = -a-b
                if (tempSet.find(c) != tempSet.end()) {
                    std::vector<int> triplet = {nums[i], nums[j], c};
                    std::sort(triplet.begin(), triplet.end());
                    uniquetriplets.insert(triplet);
                }
                tempSet.insert(nums[j]);
            }
        }

        std::vector<std::vector<int>> ans(uniquetriplets.begin(), uniquetriplets.end());
        return ans;
    }

    std::vector<std::vector<int>> threeSum2Pointer(std::vector<int> &nums) {
        std::vector<std::vector<int>> ans;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {

            if (i > 0 && nums[i] == nums[i-1]) continue; //skipping the duplicate value

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j<k && nums[j] == nums[j-1]) {
                        j++;
                    }

                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ans;
    }

    void solution() {
        std::vector<int> x = {-1, 0, 1, 2, -1, -4};
        std::vector<std::vector<int>> ans = threeSum(x);
        std::cout << "Three sum triplets: ";
        for (int i = 0; i < ans.size(); ++i) {
            std::cout << "{";
            for (auto &a: ans[i]) {
                std::cout << a << " ";
            }
            std::cout << "}, ";
        }
        std::cout << std::endl;

        std::vector<std::vector<int>> ans2 = threeSumOptimized(x);
        std::cout << "Three sum triplets Optimized: ";
        for (auto &i: ans2) {
            std::cout << "{";
            for (auto &a: i) {
                std::cout << a << " ";
            }
            std::cout << "}, ";
        }
        std::cout << std::endl;

        std::vector<std::vector<int>> ans3 = threeSum2Pointer(x);
        std::cout << "Three sum triplets with 2 pointer: ";
        for (auto &i: ans3) {
            std::cout << "{";
            for (auto &a: i) {
                std::cout << a << " ";
            }
            std::cout << "}, ";
        }
        std::cout << std::endl;
    }

};


#endif //LEETCODE_THREESUM_H
