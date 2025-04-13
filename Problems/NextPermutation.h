
#ifndef LEETCODE_NEXTPERMUTATION_H
#define LEETCODE_NEXTPERMUTATION_H


#include <vector>
#include <algorithm>
#include <iostream>

class NextPermutation {
public:
    void nextPermutation(std::vector<int> &nums) {
        // 1,2,5,4,3
        // find the pivot nums[i] < nums[i+1]                           1, |2| ,5,4,3
        // find the right most element > pivot, swap it with pivot      1,  3  ,5,4,2
        // reverse elements from pivot+1 to n-1                         1,  3  ,2,4,5

        int pivot = -1;
        //find the pivot
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) {
            //5,4,3,2,1  reverse (or sort) the array
            int i = 0;
            int j = nums.size() - 1;
            while (i <= j) {
                std::swap(nums[i++], nums[j--]);
            }

            // OR std::reverse(nums.begin(), nums.end());
            return;
        }

        //find the rightmost element greater than pivot
        for (int i = nums.size() - 1; i > pivot; --i) {
            if (nums[i] > nums[pivot]) {
                std::swap(nums[i], nums[pivot]);
                break;
            }
        }

        //reverse the remaining array
        std::reverse(nums.begin() + (pivot + 1), nums.end());
    }

    void solution() {
        std::vector<int> vec = {1, 2, 3, 6, 5, 4};
        std::cout << "Next permutation: ";
        nextPermutation(vec);
        for (auto &a: vec) {
            std::cout << a << " ";
        }
        std::cout << std::endl;

    }
};


#endif //LEETCODE_NEXTPERMUTATION_H
