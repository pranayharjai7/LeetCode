#ifndef LEETCODE_FIRSTMISSINGNONNEGATIVENUMBER_H
#define LEETCODE_FIRSTMISSINGNONNEGATIVENUMBER_H

#include <vector>
#include <set>

class FirstMissingNonNegativeNumber {
public:
    int missingNonNegativeNumber(std::vector<int> &nums) {
        std::set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                set.emplace(nums[i]);
            }
        }

        for (int i = 0; true ; ++i) {
            if (set.find(i) == set.end()) {
                return i;
            }
        }
    }
};


#endif //LEETCODE_FIRSTMISSINGNONNEGATIVENUMBER_H
