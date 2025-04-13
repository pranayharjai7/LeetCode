#ifndef LEETCODE_SINGLEELEMENTINSORTEDARRAY_H
#define LEETCODE_SINGLEELEMENTINSORTEDARRAY_H


#include <vector>
#include <iostream>

class SingleElementInSortedArray {
public:
    int singleNonDuplicate(std::vector<int> &nums) {
        bool isUnique = true;
        int newNum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (isUnique) {
                if (newNum != nums[i]) {
                    return newNum;
                }
                isUnique = false;
            } else {
                if (newNum != nums[i]) {
                    newNum = nums[i];
                    isUnique = true;
                }
            }
        }
        return newNum;
    }

    int singleNonDuplicateWithBinarySearch(std::vector<int> &nums) {
        int first = 0;
        int last = nums.size() - 1;

        if (nums.size() == 1) return nums[0];
        if (nums[first] != nums[first + 1]) return nums[first];
        if (nums[last] != nums[last - 1]) return nums[last];

        while (first <= last) {
            int mid = first + (last-first)/2;
            if ((nums[mid - 1] != nums[mid]) && (nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }
            if (mid%2 == 0) {
                if (nums[mid - 1] == nums[mid]) {
                    last = mid - 1;
                } else {
                    first = mid + 1;
                }
            } else {
                if (nums[mid] == nums[mid + 1]) {
                    last = mid - 1;
                } else {
                    first = mid + 1;
                }
            }
        }

        return -1;
    }


    void solution() {
        std::vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
        int ans = singleNonDuplicate(nums);
        std::cout << "Single element in sorted array: " << ans << std::endl;
        int ans2 = singleNonDuplicateWithBinarySearch(nums);
        std::cout << "Single element in sorted array with Binary Search: " << ans2 << std::endl;
    }
};


#endif //LEETCODE_SINGLEELEMENTINSORTEDARRAY_H
