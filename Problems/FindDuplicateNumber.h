#ifndef LEETCODE_FINDDUPLICATENUMBER_H
#define LEETCODE_FINDDUPLICATENUMBER_H


#include <vector>
#include <iostream>
#include <unordered_set>

class FindDuplicateNumber {
public:

    int findDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.find(nums[i]) != set.end()) {
                return nums[i];
            }
            set.insert(nums[i]);
        }
        return -1;
    }

    int findDuplicateOptimized(std::vector<int>& nums) {
        //using slow-fast pointer approach
        //treating the array as linked-list
        //index 0 has value 3, so 0 will point to 3rd index. 3rd index has value 5, so 3 will point to 5th index.
        // When there exists a duplicate value, a cyclic linked-list will be formed.
        //cyclic linked-list are always solved with slow-fast pointer approach
        int slowPtr = nums[0];
        int fastPtr = nums[0];

        do {
            slowPtr = nums[slowPtr]; //+1
            fastPtr = nums[nums[fastPtr]]; //+2
        } while (slowPtr != fastPtr);

        slowPtr = nums[0];

        while (slowPtr != fastPtr) {
            slowPtr = nums[slowPtr]; // +1
            fastPtr = nums[fastPtr]; // +1
        }

        return slowPtr;
    }


    //Slow fast pointer approach:
    //1. start the slowPtr and fastPtr with arr[0]
    //2. increase slowPtr with +1 and fastPtr with +2.
    //3. When slowPtr == fastPtr (will happen in case of cyclic Linked-list) slowPtr = 0;
    //4. Now move slowPtr and fastPtr with same speed (+1)
    //5. when slowPtr == fastPtr, it will meet at beginning of cycle.
    void solution() {
        std::vector<int> nums = {1,3,4,2,2};
        int ans = findDuplicate(nums);
        std::cout << "Duplicate number: " << ans << std::endl;
    }
};


#endif //LEETCODE_FINDDUPLICATENUMBER_H
