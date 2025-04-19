#ifndef LEETCODE_SLIDINGWINDOWMAXIMUM_H
#define LEETCODE_SLIDINGWINDOWMAXIMUM_H


#include <vector>
#include <deque>

class SlidingWindowMaximum {
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        std::vector<int> ans;
        for (int i = 0; i <= nums.size() - k; ++i) {
            int currMax = nums[i];
            for (int j = i + 1; j < i + k; ++j) {
                currMax = std::max(nums[j], currMax);
            }
            ans.push_back(currMax);
        }

        return ans;
    }

    std::vector<int> maxSlidingWindowOptimized(std::vector<int> &nums, int k) {
        std::deque<int> dq;     //stores the indexes, front() should have the max value's index
        std::vector<int> ans;

        //1st Window
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {     //remove non-viable values
                dq.pop_back();
            }
            dq.push_back(i);
        }

        //rest of the windows
        for (int i = k; i < nums.size(); ++i) {
            ans.push_back(nums[dq.front()]);

            //remove elements which are not part of current window from the front
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            //remove the smaller values from the end
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {     //remove non-viable values
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        return ans;
    }
};


#endif //LEETCODE_SLIDINGWINDOWMAXIMUM_H
