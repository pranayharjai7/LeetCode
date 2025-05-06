#ifndef LEETCODE_EXTRACHARINSTRING_H
#define LEETCODE_EXTRACHARINSTRING_H


#include <string>
#include <vector>
#include <unordered_set>

class ExtraCharInString {
public:
    int minExtraChar(std::string s, std::vector<std::string> &dictionary) {
        std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());

        std::vector<int> dp(s.size()+1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= s.size(); ++i) {
            dp[i] = dp[i-1] + 1;

            for (int j = 0; j < i; ++j) {
                std::string subStr = s.substr(j, i-j);
                if (dict.find(subStr) != dict.end()) {
                    dp[i] = std::min(dp[i], dp[j]);
                }
            }
        }

        return dp[s.size()];
    }
};


#endif //LEETCODE_EXTRACHARINSTRING_H
