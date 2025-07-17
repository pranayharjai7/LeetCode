#ifndef LEETCODE_PEAKINDEXINMOUNTAIN_H
#define LEETCODE_PEAKINDEXINMOUNTAIN_H


#include <vector>
#include <climits>
#include <iostream>

class PeakIndexInMountain {
public:
    int peakIndexInMountainArray(std::vector<int> &arr) {
        int max = INT_MIN;
        int peakIndex = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
                peakIndex = i;
            }
        }
        return peakIndex;
    }

    int peakIndexInMountainArrayOptimized(std::vector<int> &arr) {
        int i = 1;
        while (i < arr.size() - 1) {
            if ((arr[i - 1] < arr[i]) && (arr[i] > arr[i + 1])) { // peak element is always greater than left and right element.
                return i;
            }
            i++;
        }
        return i;
    }

    int peakIndexInMountainArrayBinarySearch(std::vector<int> &arr) {
        int first = 1; // Because peak can never be first value
        int last = arr.size() - 2; //Because peak can never be last value

        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid] < arr[mid + 1]) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        return -1;
    }

    void solution() {
        std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 10, 5, 2, -1};
        int index = peakIndexInMountainArray(vec);
        std::cout << "Peak Value in Mountain Array: " << vec[index] << " And Index: " << index << std::endl;
        int index2 = peakIndexInMountainArrayOptimized(vec);
        std::cout << "Peak Value in Mountain Array Optimized: " << vec[index2] << " And Index: " << index2 << std::endl;
        int index3 = peakIndexInMountainArrayBinarySearch(vec);
        std::cout << "Peak Value in Mountain Array Binary Search: " << vec[index3] << " And Index: " << index3 << std::endl;
    }
};


#endif //LEETCODE_PEAKINDEXINMOUNTAIN_H
