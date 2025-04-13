#ifndef LEETCODE_WATERCONTAINER_H
#define LEETCODE_WATERCONTAINER_H

#include <vector>
#include <iostream>

class WaterContainer {
public:
    int maxArea(std::vector<int>& height) {
        int maxArea = 0;
        for (int i = 0; i < height.size()-1; ++i) {
            for (int j = i+1; j < height.size(); ++j) {
                int containerHeight = std::min(height[i], height[j]);
                int width = j-i;
                int area = containerHeight*width;
                maxArea = std::max(area, maxArea);
            }
        }

        return maxArea;
    }

    int maxArea2Pointer(std::vector<int> &height) {
        int maxArea = 0;
        int first = 0;
        int last = height.size() - 1;
        while (first < last) {
            int width = last-first;
            int containerHeight = std::min(height[first], height[last]);
            int waterArea = containerHeight*width;
            maxArea = std::max(maxArea, waterArea);
            if (height[first] < height[last]) {
                first++;
            } else {
                last--;
            }

        }
        return maxArea;
    }

    void solution() {
        std::vector<int> height = {1,8,6,2,5,4,8,3,7};
        int waterArea = maxArea(height);
        std::cout << "Max area of Water: " << waterArea << std::endl;
        int waterArea2 = maxArea2Pointer(height);
        std::cout << "Max area of Water (Optimized): " << waterArea2 << std::endl;
    }
};


#endif //LEETCODE_WATERCONTAINER_H
