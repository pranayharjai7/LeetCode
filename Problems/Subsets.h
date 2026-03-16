#ifndef LEETCODE_SUBSETS_H
#define LEETCODE_SUBSETS_H

#include <vector>
#include <iostream>

class Subsets {
public:
    void printAllSubsets(std::vector<int> arr) {
        std::vector<std::vector<int>> vec2D;

        for (int i = 0; i < arr.size(); ++i) {

        }
    }

    void printAllSubsetsRecursion(std::vector<int> &arr, std::vector<int> &ans, int i) {
        if (i == arr.size()) {
            for (auto &a: ans) {
                std::cout << a << " ";
            }
            std::cout << std::endl;
            return;
        }
        ans.push_back(arr[i]);                          //include
        printAllSubsetsRecursion(arr, ans, i+1);  //include
        ans.pop_back();                                 //backtrack
        printAllSubsetsRecursion(arr, ans, i+1);  //exclude
    }

    void printDuplicateSubsets(std::vector<int>& nums, std::vector<int> ans, int i, std::vector<std::vector<int>>& allSubsets) {
        if (i ==nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        printDuplicateSubsets(nums, ans, i+1, allSubsets);
        ans.pop_back();
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[i]) idx++;
        printDuplicateSubsets(nums, ans, idx, allSubsets);
    }


    void solution() {
        std::vector<int> arr = {1,2,3};
        std::vector<int> ans;
        std::cout << "print All Subsets Recursion: \n";
        printAllSubsetsRecursion(arr, ans, 0);

    }
};


#endif //LEETCODE_SUBSETS_H