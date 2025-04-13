#ifndef LEETCODE_SINGLENUMBER_H
#define LEETCODE_SINGLENUMBER_H

#include <vector>
#include <iostream>

class SingleNumber {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = 0;
        for (auto &num: nums) {
            ans ^= num;
        }
        return ans;
    }

    void solution() {
        std::vector<int> vec = {4,1,2,1,2};
        int num = singleNumber(vec);
        std::cout << "Single number in array: " << num << std::endl;
    }
};


#endif //LEETCODE_SINGLENUMBER_H
