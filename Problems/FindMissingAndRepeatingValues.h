#ifndef LEETCODE_FINDMISSINGANDREPEATINGVALUES_H
#define LEETCODE_FINDMISSINGANDREPEATINGVALUES_H

#include <vector>
#include <unordered_set>
#include <iostream>

class FindMissingAndRepeatingValues {
public:
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
        std::vector<int> ans;
        std::unordered_set<int> set;
        int n = grid.size();

        int actualSum = 0;
        int expectedSum = (n*n)*((n*n) + 1)/2;
        int repeatingValue = 0;
        int missingValue = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                actualSum += grid[i][j];
                if (set.find(grid[i][j]) != set.end()) {
                    repeatingValue = grid[i][j];
                    ans.push_back(repeatingValue);
                }
                set.insert(grid[i][j]);
            }

        }

        //expected sum of all values: 1+2+3+....+n^2
        //Actual sum = expected sum + repeatingValue - missingVal
        // => missingValue = expectedSum + repeatingValue - actualSum;
        missingValue = expectedSum + repeatingValue - actualSum;
        ans.push_back(missingValue);
        return ans;
    }

    void solution() {
        std::vector<std::vector<int>> grid = {{9,1,7},
                                              {8,9,2},
                                              {3,4,6}};
        std::vector<int> ans = findMissingAndRepeatedValues(grid);
        std::cout << "Repeated value in grid: " << ans[0] << ", missing value: " << ans[1] << std::endl;
    }
};


#endif //LEETCODE_FINDMISSINGANDREPEATINGVALUES_H
