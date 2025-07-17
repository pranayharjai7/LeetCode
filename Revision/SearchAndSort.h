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

    void solution() {
        std::vector<int> vec = {-1, 0, 3, 4, 5, 9, 12};
        int target = 9;
        std::cout << "Searching " << target << " using binary search, found at: " << binarySearch(vec, target) << std::endl;
        std::cout << "Searching " << target << " using binary search REC, found at: " << binarySearchRec(vec, target, 0 , vec.size() - 1) << std::endl;

        std::vector<int> vec2 = {4, 5, 9, 12, -1, 0, 3};
        std::cout << "Searching " << target << " in rotated sorted array, found at: " << searchInRotatedSortedArray(vec2, target) << std::endl;

    }
};


#endif //SEARCHANDSORT_H
