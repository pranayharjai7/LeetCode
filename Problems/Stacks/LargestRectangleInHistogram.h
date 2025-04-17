#ifndef LEETCODE_LARGESTRECTANGLEINHISTOGRAM_H
#define LEETCODE_LARGESTRECTANGLEINHISTOGRAM_H

#include <vector>
#include <climits>

class LargestRectangleInHistogram {
public:
    int largestRectangleArea(std::vector<int> &heights) {
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int minHeight = heights[i];
            for (int j = i; j < heights.size(); ++j) {
                int width = j - i + 1;
                minHeight = std::min(heights[j], minHeight);
                int area = width * minHeight;
                maxArea = std::max(maxArea, area);
            }
        }

        return maxArea;
    }

    int calcWidth(std::vector<int> &heights, int i) {
        int leftNearestSmallerValueIndex = 0;
        int rightNearestSmallerValueIndex = 0;

        for (int j = i - 1; j >= 0; --j) {
            if (heights[j] < heights[i]) {
                leftNearestSmallerValueIndex = j;
                break;
            }
        }

        for (int j = i + 1; j < heights.size(); ++j) {
            if (heights[j] < heights[i]) {
                rightNearestSmallerValueIndex = j;
                break;
            }
        }

        return rightNearestSmallerValueIndex - leftNearestSmallerValueIndex - 1;
    }

    int largestRectangleAreaOptimized(std::vector<int> &heights) {
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int width = calcWidth(heights, i);
            int currArea = heights[i] * width;
            maxArea = std::max(currArea, maxArea);
        }

        return maxArea;
    }
};


#endif //LEETCODE_LARGESTRECTANGLEINHISTOGRAM_H
