#ifndef LEETCODE_QUICKSORT_H
#define LEETCODE_QUICKSORT_H


#include <vector>
#include <iostream>

class QuickSort {
public:

    //1. Select the Pivot
    //      Pivot can be any element (first, last, mid, any random)
    //2. Partition your array around the pivot
    //      Put the smaller values of the array compared to pivot to the left of pivot (needn't be sorted)
    //      Put the greater values of the array compared to pivot to the right of pivot (needn't be sorted)
    //3. Recall the quick sort for left and right half recursively.

    int partition(std::vector<int> &arr, int start, int end) {
        int pivot = arr[end];
        int idx = start;

        for (int i = start; i < end; ++i) {
            if (arr[i] <= pivot) {
                std::swap(arr[i], arr[idx++]);
            }
        }
        std::swap(arr[end], arr[idx]);
        return idx;
    }

    void quickSort(std::vector<int> &arr, int start, int end) {
        if (start >= end) {
            return;
        }

        int pivotIndex = partition(arr, start, end);    //returns the index where the pivot element should be in a sorted array
        quickSort(arr, start, pivotIndex - 1);  //left half
        quickSort(arr, pivotIndex + 1, end);    //right half
    }

    void solution() {
        //Pivot and Partition
        // TC (avg.) = O(nlogn)
        // TC (worst) = O(n^2) => when Pivot is repeatedly the smallest element or the largest element of array
        // SC = O(1) ignoring the space occupied by call stack of recursion
        // SC (avg) = O(logn) if not ignoring the call stack
        // SC (worst) = O(n) the recursion stack will be as deep as "n" and will sort 1 element at a time, giving TC = O(n^2)
        // When we have large data, we use quick sort
        std::vector<int> arr = {12, 31, 35, 8, 32, 17};
        quickSort(arr, 0, arr.size()-1);
        std::cout << "Quick sort O(nlogn): ";
        for (auto &i: arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};


#endif //LEETCODE_QUICKSORT_H
