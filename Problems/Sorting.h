#ifndef LEETCODE_SORTING_H
#define LEETCODE_SORTING_H


#include <vector>
#include <iostream>

class Sorting {
public:
    void bubbleSort(std::vector<int> &arr) {
        for (int i = 0; i < arr.size() - 1; ++i) {
            bool isSwap = false;
            for (int j = 0; j < arr.size() - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    isSwap = true;
                }
            }
            if (!isSwap) return;
        }
    }

    void selectionSort(std::vector<int> &arr) {
        for (int i = 0; i < arr.size() - 1; ++i) {
            int smallest = i;
            for (int j = i+1; j < arr.size(); ++j) {
                if (arr[j] < arr[smallest]) {
                    smallest = j;
                }
            }
            std::swap(arr[i], arr[smallest]);
        }
    }

    void insertionSort(std::vector<int>& arr) {
        // 1 3 4 2 5
        for (int i = 1; i < arr.size(); ++i) {
            int curr = arr[i];
            int j = i-1;
            while (j >= 0 && arr[j] > curr) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = curr;
        }
    }

    void sortColors_0_1_2(std::vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        for (auto &num: nums) {
            if (num == 0) zeros++;
            else if (num == 1) ones++;
            else twos++;
        }

        int index = 0;
        for (int i = 0; i < zeros; ++i) {
            nums[index++] = 0;
        }
        for (int i = 0; i < ones; ++i) {
            nums[index++] = 1;
        }
        for (int i = 0; i < twos; ++i) {
            nums[index++] = 2;
        }
    }

    void sortColors_0_1_2_optimized(std::vector<int>& nums) {
        //Dutch national flag algorithm // single pass O(n)
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                std::swap(nums[high], nums[mid]);
                high--;
            }
        }
    }

    void solution() {
        std::vector<int> vec = {5,4,3,2,1};
        std::cout << "Bubble sorted array: ";
        bubbleSort(vec);
        for (auto &a: vec) std::cout << a << " ";
        std::cout << std::endl;

        std::vector<int> vec2 = {5,4,3,2,1};
        std::cout << "Selection sorted array: ";
        selectionSort(vec2);
        for (auto &a: vec2) std::cout << a << " ";
        std::cout << std::endl;

        std::vector<int> vec3 = {5,4,3,2,1};
        std::cout << "Insertion sorted array: ";
        insertionSort(vec3);
        for (auto &a: vec3) std::cout << a << " ";
        std::cout << std::endl;

        std::vector<int> vec4 = {2,0,2,1,1,0};
        std::cout << "sorted colors array for 0,1,2's: ";
        sortColors_0_1_2(vec4);
        for (auto &a: vec4) std::cout << a << " ";
        std::cout << std::endl;

        std::vector<int> vec5 = {2,0,2,1,1,0};
        std::cout << "sorted colors array for 0,1,2's optimized: ";
        sortColors_0_1_2_optimized(vec5);
        for (auto &a: vec5) std::cout << a << " ";
        std::cout << std::endl;
    }
};


#endif //LEETCODE_SORTING_H
