#ifndef LEETCODE_PERMUTATIONS_H
#define LEETCODE_PERMUTATIONS_H


#include <vector>
#include <iostream>
#include <set>

class Permutations {
public:

    void getPerms(std::vector<int> &nums, int idx, std::vector<std::vector<int>> &ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            std::swap(nums[idx], nums[i]);      //swapping for next permutation
            getPerms(nums, idx + 1, ans);
            std::swap(nums[idx], nums[i]);      // swapping back for backtracking to previous permutation
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        std::vector<std::vector<int>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }

    void getPermStr(std::string &s, int idx, std::vector<std::string> &ans) {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }

        for (int i = idx; i < s.size(); ++i) {
            std::swap(s[idx], s[i]);
            getPermStr(s, idx + 1, ans);
            std::swap(s[idx], s[i]);
        }
    }

    std::vector<std::string> permuteStr(std::string s) {
        std::vector<std::string> ans;
        getPermStr(s, 0, ans);
        return ans;
    }

    void getPermsUnique(std::vector<int> &nums, int idx, std::set<std::vector<int>> &s) {
        if (idx == nums.size()) {
            s.insert(nums);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            std::swap(nums[idx], nums[i]);      //swapping for next permutation
            getPermsUnique(nums, idx + 1, s);
            std::swap(nums[idx], nums[i]);      // swapping back for backtracking to previous permutation
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {

        std::set<std::vector<int>> s;
        getPermsUnique(nums, 0, s);
        std::vector<std::vector<int>> ans(s.begin(), s.end());
        return ans;
    }

    void solution() {
        std::cout << "Permutations of array (O(n!*n)): \n";
        std::vector<int> nums = {1, 2, 3};
        auto ans = permute(nums);
        for (auto &a: ans) {
            std::cout << "{";
            for (auto &i: a) {
                std::cout << i << " ";
            }
            std::cout << "}\n";
        }

        std::cout << "Permutations of String (O(n!*n)): \n";
        std::string str = "abc";
        auto strVec = permuteStr(str);
        for (auto &s: strVec) {
            std::cout << s << std::endl;
        }

        std::cout << "Permutations of duplicates array (O(n!*n)): \n";
        std::vector<int> nums2 = {1, 1, 2};
        auto ans2 = permuteUnique(nums2);
        for (auto &a: ans2) {
            std::cout << "{";
            for (auto &i: a) {
                std::cout << i << " ";
            }
            std::cout << "}\n";
        }
    }
};


#endif //LEETCODE_PERMUTATIONS_H
