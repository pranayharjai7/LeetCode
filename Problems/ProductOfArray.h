//
// Created by harjai on 03-Mar-25.
//

#ifndef LEETCODE_PRODUCTOFARRAY_H
#define LEETCODE_PRODUCTOFARRAY_H


#include <vector>
#include <iostream>

class ProductOfArray {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> ans(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (j != i) {
                    ans[i] *= nums[j];
                }
            }
        }
        return ans;
    }

    std::vector<int> productExceptSelfOptimizedTime(std::vector<int>& nums) {
        std::vector<int> ans(nums.size(),1);
        std::vector<int> leftProd(nums.size(), 1);
        std::vector<int> rightProd(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            leftProd[i] = leftProd[i-1]*nums[i-1];
        }
        for(int i = nums.size()-2; i >= 0; --i) {
            rightProd[i] = rightProd[i+1]*nums[i+1];
        }
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = leftProd[i]*rightProd[i];
        }
        return ans;
    }

    std::vector<int> productExceptSelfOptimizedSpaceTime(std::vector<int>& nums) {
        std::vector<int> ans(nums.size(),1);
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = ans[i-1]*nums[i-1];
        }
        int suffix = 1;
        for(int i = nums.size()-2; i >= 0; --i) {
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }
        return ans;
    }


    void solution() {
        std::vector<int> nums = {1,2,3,4};
        std::vector<int> answer = productExceptSelf(nums);
        std::cout << "Product Except Self: ";
        for (auto &a: answer) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
        std::vector<int> answer2 = productExceptSelfOptimizedTime(nums);
        std::cout << "Product Except Self Optimized Time: ";
        for (auto &a: answer2) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
        std::vector<int> answer3 = productExceptSelfOptimizedSpaceTime(nums);
        std::cout << "Product Except Self Optimized Space and Time: ";
        for (auto &a: answer3) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }
};


#endif //LEETCODE_PRODUCTOFARRAY_H
