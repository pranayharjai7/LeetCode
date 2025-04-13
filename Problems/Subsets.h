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
        ans.push_back(arr[i]);
        printAllSubsetsRecursion(arr, ans, i+1);
        ans.pop_back();
        printAllSubsetsRecursion(arr, ans, i+1);
    }

    void solution() {
        std::vector<int> arr = {1,2,3};
        std::vector<int> ans;
        std::cout << "print All Subsets Recursion: \n";
        printAllSubsetsRecursion(arr, ans, 0);

    }
};


#endif //LEETCODE_SUBSETS_H