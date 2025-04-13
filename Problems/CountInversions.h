#ifndef LEETCODE_COUNTINVERSIONS_H
#define LEETCODE_COUNTINVERSIONS_H


#include <vector>
#include <iostream>

class CountInversions {
public:
    int countInversions(std::vector<int> &arr) {
        int count = 0;

        for (int i = 0; i < arr.size() - 1; ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                if (arr[i] > arr[j]) {
                    count++;
                }
            }
        }

        return count;
    }

    int merge(std::vector<int> &arr, int start, int mid, int end) {
        std::vector<int> temp(end - start + 1, 0);

        int inversionCount = 0;
        int i = start;
        int j = mid + 1;
        int index = 0;
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp[index++] = arr[i++];
            } else {
                temp[index++] = arr[j++];
                inversionCount += mid - i + 1;
            }
        }

        while (i <= mid) {
            temp[index++] = arr[i++];
        }

        while (j <= end) {
            temp[index++] = arr[j++];
        }

        index = 0;
        while (index < temp.size()) {
            arr[start + index] = temp[index];
            index++;
        }
        return inversionCount;
    }

    int mergeSort(std::vector<int> &arr, int start, int end) {
        if (start >= end) {
            return 0;
        }

        int mid = start + (end - start) / 2;
        int leftCount = mergeSort(arr, start, mid);
        int rightCount = mergeSort(arr, mid + 1, end);

        int currCount = merge(arr, start, mid, end);

        return leftCount + rightCount + currCount;
    }

    int countInversionsOptimized(std::vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }

    void solution() {
        std::vector<int> arr = {6, 3, 5, 2, 7};
        std::cout << "Total inversions in array (O(n^2)): " << countInversions(arr) << std::endl;
        std::vector<int> arr2 = {6, 3, 5, 2, 7};
        std::cout << "Total inversions in array (Optimized with merge sort) (O(nlogn)): ";
        std::cout << countInversionsOptimized(arr2) << std::endl;
    }
};


#endif //LEETCODE_COUNTINVERSIONS_H
