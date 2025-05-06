#ifndef LEETCODE_MINIMUMSTROKESOFPAINT_H
#define LEETCODE_MINIMUMSTROKESOFPAINT_H


#include <vector>
#include <iostream>

class MinimumStrokesOfPaint {
public:
    int minimumStrokes(std::vector<int> planks) {   //O(n * max_height)
        int strokesCount = 0;
        int i = 0;
        while (i < planks.size()) {
            if (planks[i] == 0) {
                i++;
                continue;
            }
            int width = 0;
            for (int j = i; j < planks.size() && planks[j] >= 1; j++) {
                width++;
            }

            if (planks[i] > width) {
                planks[i] = 0;
                i++;
            } else {
                for (int j = i; j < i + width; j++) {
                    if (planks[j] >= 1)
                        planks[j]--;
                }
            }
            strokesCount++;
        }
        return strokesCount;
    }

    int minimumStrokesOptimized(std::vector<int> planks) {  //O(n)
        int strokesCount = 0;
        int i = 0;
        while (i < planks.size()) {
            if (planks[i] == 0) {
                i++;
                continue;
            }

            int width = 0;
            int minHeight = planks[i];
            for (int j = i; j < planks.size() && planks[j] >= 1; ++j) {
                minHeight = std::min(minHeight, planks[j]);
                width++;
            }

            if (planks[i] > width) {
                planks[i] = 0;
                strokesCount++;
                i++;
            } else {
                for (int j = i; j < i + width; ++j) {
                    planks[j] -= minHeight;
                }
                strokesCount += minHeight;
            }
        }

        return strokesCount;
    }

    void solution() {
        std::cout << "Minimum strokes to paint the fence\n";
        std::vector<int> planks1 = {4, 3, 2, 1, 0, 1};  // Expected output: 5 strokes
        std::vector<int> planks2 = {0, 0, 0, 0};  // Expected output: 0 strokes
        std::vector<int> planks = {3,3,3,3,3};

        std::cout << "For Fence {";
        for (auto &p: planks) {
            std::cout << p << " ";
        }
        std::cout << "}: " << minimumStrokes(planks) << std::endl;
        std::cout << "For Fence {";
        for (auto &p: planks) {
            std::cout << p << " ";
        }
        std::cout << "}: " << minimumStrokesOptimized(planks) << std::endl;
    }
};


#endif //LEETCODE_MINIMUMSTROKESOFPAINT_H
