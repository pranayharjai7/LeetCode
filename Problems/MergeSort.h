#ifndef LEETCODE_MERGESORT_H
#define LEETCODE_MERGESORT_H


#include <vector>
#include <iostream>

class MergeSort {
public:

    void merge(std::vector<int> &arr, int start, int mid, int end) {    //O(n)
        std::vector<int> temp;
        int i = start;  //points to the start of left array
        int j = mid+1;  //points to the start of right array

        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) {  //leftover left array
            temp.push_back(arr[i++]);
        }
        while (j <= end) {  //leftover right array
            temp.push_back(arr[j++]);
        }

        for (int idx = 0; idx < temp.size(); ++idx) {   //copying back to original array
            arr[start+idx] = temp[idx];
        }
    }

    void mergeSort(std::vector<int> &arr, int start, int end) {     //recursively called O(logn) times
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid); //left half
        mergeSort(arr, mid + 1, end); //right half

        merge(arr, start, mid, end);    //O(n)
    }

    void solution() {
        //divide and conquer
        //divide until you have single elements.
        //backtrack while merging the elements in sorted manner.

        //TC = O(nlogn) => logn are number of calls, work done in each call = n.
        //SC = O(n)
        std::vector<int> arr = {12, 31, 35, 8, 32, 17};
        mergeSort(arr, 0, arr.size()-1);
        std::cout << "Merge sort O(nlogn): ";
        for (auto &i: arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};


#endif //LEETCODE_MERGESORT_H
