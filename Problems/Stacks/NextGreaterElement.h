#ifndef LEETCODE_NEXTGREATERELEMENT_H
#define LEETCODE_NEXTGREATERELEMENT_H


#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

class NextGreaterElement {
public:
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            int j = 0;
            for (; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) break;
            }

            int k = j + 1;
            for (; k < nums2.size(); ++k) {
                if (nums2[k] > nums2[j]) {
                    ans.push_back(nums2[k]);
                    break;
                }
            }
            if (k == nums2.size()) {
                ans.push_back(-1);
            }
        }

        return ans;
    }

    std::vector<int> nextGreaterElement2(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::vector<int> ans(nums1.size());
        std::stack<int> stack;
        std::unordered_map<int, int> uMap;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!stack.empty()) {
                if (stack.top() > nums2[i]) break;
                stack.pop();
            }
            if (!stack.empty()) {
                uMap[nums2[i]] = stack.top();
            } else {
                uMap[nums2[i]] = -1;
            }
            stack.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); ++i) {
            ans[i] = (uMap.find(nums1[i])->second);
        }

        return ans;
    }
};


#endif //LEETCODE_NEXTGREATERELEMENT_H
