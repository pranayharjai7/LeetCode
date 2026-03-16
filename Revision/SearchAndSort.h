#ifndef SEARCHANDSORT_H
#define SEARCHANDSORT_H
#include <iostream>
#include <vector>

class SearchAndSort {
public:
    int binarySearch(const std::vector<int> &vec, int target) {
        int start = 0;
        int end = vec.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (vec[mid] == target) return mid;
            if (vec[mid] < target) start = mid + 1;
            else end = mid - 1;
        }

        return -1;
    }

    int binarySearchRec(std::vector<int> &vec, int target, int start, int end) {
        if (start > end) return -1;
        int mid = start + (end - start) / 2;

        if (vec[mid] == target) return mid;
        if (vec[mid] < target) return binarySearchRec(vec, target, mid + 1, end);
        return binarySearchRec(vec, target, start, mid - 1);
    }

    int searchInRotatedSortedArray(std::vector<int> &vec, int target) {
        int start = 0;
        int end = vec.size() - 1;

        while (start <= end) {
            int mid = start + (end - start)/2;
            if (vec[mid] == target) {
                return mid;
            }

            if (vec[start] <= vec[mid]) {
                if (vec[start] <= target && target < vec[mid]) {
                    end  = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (vec[mid] < target && target <= vec[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }

    //TwoSum
    std::pair<int, int> twoSumOptimized(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> compliment;
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - nums[i];
            if (compliment.find(second) != compliment.end()) {
                return {i, compliment[second]};
            }
            compliment[first] = i;
        }

        return {};
    }

    std::pair<int, int> pairSum(std::vector<int> &sortedArray, int target) {
        int start = 0;
        int end = sortedArray.size() - 1;

        while (start < end) {
            int sum = sortedArray[start] + sortedArray[end];
            if (sum == target) {
                return {start, end};
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }
        return {};
    }

    void solution() {
        std::vector<int> vec = {-1, 0, 3, 4, 5, 9, 12};
        int target = 9;
        std::cout << "Searching " << target << " using binary search, found at: " << binarySearch(vec, target) << std::endl;
        std::cout << "Searching " << target << " using binary search REC, found at: " << binarySearchRec(vec, target, 0 , vec.size() - 1) << std::endl;

        std::vector<int> vec2 = {4, 5, 9, 12, -1, 0, 3};
        std::cout << "Searching " << target << " in rotated sorted array, found at: " << searchInRotatedSortedArray(vec2, target) << std::endl;

        int target2 = 15;
        std::cout << "Find 2 integers whose sum is " << target << " at indexes: " << twoSumOptimized(vec2, target2).first << ", " << twoSumOptimized(vec2, target2).second << std::endl;

        std::cout << "Find 2 integers whose sum is " << target << " at indexes: " << pairSum(vec, target2).first << ", " << pairSum(vec, target2).second << std::endl;

    }
};


#endif //SEARCHANDSORT_H
