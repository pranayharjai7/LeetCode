#ifndef LEETCODE_MINIMUMUNSORTEDSUBARRAY_H
#define LEETCODE_MINIMUMUNSORTEDSUBARRAY_H

#include <vector>
#include <climits>

/*
 * Given an array,
 * Return the minimum possible subarray which when sorted, the entire array will become sorted.
 */
class MinimumUnsortedSubarray {
public:
    std::vector<int> minimumPossibleSubarrayUnsorted(std::vector<int> &arr) {
        int start = 0;
        int end = arr.size() - 1;

        while (start < arr.size() - 1) {
            if (arr[start] > arr[start + 1]) {
                break;
            }
            start++;
        }

        //whole array was sorted already
        if (start == arr.size() - 1) return arr;

        while (end > 0) {
            if (arr[end] < arr[end - 1]) {
                break;
            }
            end--;
        }

        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = start; i <= end; i++) {
            minVal = std::min(minVal, arr[i]);
            maxVal = std::max(maxVal, arr[i]);
        }

        while (start > 0 && arr[start - 1] > minVal) {
            start--;
        }

        while (end < arr.size() - 1 && arr[end + 1] < maxVal) {
            end++;
        }

        return std::vector<int>(arr.begin() + start, arr.begin() + end);
    }
};


#endif //LEETCODE_MINIMUMUNSORTEDSUBARRAY_H
