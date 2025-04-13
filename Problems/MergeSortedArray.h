#ifndef LEETCODE_MERGESORTEDARRAY_H
#define LEETCODE_MERGESORTEDARRAY_H


#include <vector>
#include <iostream>

class MergeSortedArray {
public:
    std::vector<int> merge(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i++]);
            } else {
                ans.push_back(nums2[j++]);
            }
        }
        for (; i < nums1.size(); i++) {
            ans.push_back(nums1[i]);
        }
        for (; j < nums2.size(); j++) {
            ans.push_back(nums2[j]);
        }

        return ans;
    }

    void mergeInSameArray(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int idx = m+n-1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[idx--] = nums1[i--];
            } else {
                nums1[idx--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[idx--] = nums2[j--];
        }
    }

    void solution() {
        std::vector<int> vec1 = {1,2,3,4,5,6};
        std::vector<int> vec2 = {2,5,6,9,21,34,56,78,100};
        std::cout << "Merge 2 sorted array: ";
        std::vector<int> ans = merge(vec1, vec2);
        for (auto& a: ans) {
            std::cout << a << " ";
        }
        std::cout << std::endl;

        std::vector<int> vec3 = {2,5,6,0,0,0};
        std::vector<int> vec4 = {1,2,3};
        std::cout << "Merge 2 sorted array in the first array O(m+n): ";
        mergeInSameArray(vec3, 3, vec4, vec4.size());
        for (auto& a: vec3) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }
};


#endif //LEETCODE_MERGESORTEDARRAY_H
