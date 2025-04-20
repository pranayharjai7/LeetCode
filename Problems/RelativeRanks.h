#ifndef LEETCODE_RELATIVERANKS_H
#define LEETCODE_RELATIVERANKS_H

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

class RelativeRanks {
public:
    int binarySearch(std::vector<int> &sortedScore, int val) {
        int start = 0;
        int end = sortedScore.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (sortedScore[mid] == val) {
                return mid;
            } else if (sortedScore[mid] < val) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }

    std::vector<std::string> findRelativeRanks(std::vector<int> &score) {
        std::vector<int> sortedScore(score);
        std::sort(sortedScore.begin(), sortedScore.end(), std::greater<int>());
        std::vector<std::string> s;
        for (int i = 0; i < score.size(); i++) {
            if (score[i] == sortedScore[0]) {
                s.emplace_back("Gold Medal");
            } else if (score[i] == sortedScore[1]) {
                s.emplace_back("Silver Medal");
            } else if (score[i] == sortedScore[2]) {
                s.emplace_back("Bronze Medal");
            } else {
                s.emplace_back(std::to_string(binarySearch(sortedScore, score[i]) + 1));
            }
        }

        return s;
    }

    void solution() {
        std::vector<int> score = {5, 4, 3, 2, 1};
        std::vector<std::string> ans = findRelativeRanks(score);
        std::cout << "Relative ranks: ";
        for (auto &s: ans) {
            std::cout << s << ", ";
        }
        std::cout << std::endl;
    }
};


#endif //LEETCODE_RELATIVERANKS_H
