#ifndef LEETCODE_PALINDROMEPARTITIONING_H
#define LEETCODE_PALINDROMEPARTITIONING_H


#include <vector>
#include <string>
#include <iostream>

class PalindromePartitioning {
public:

    bool isPalindrome(std::string &str) {
        int start = 0;
        int end = str.length() - 1;
        while (start < end) {
            if (!isalnum(str[start])) {
                start++;
                continue;
            }
            if (!isalnum(str[end])) {
                end--;
                continue;
            }
            if (tolower(str[start]) != tolower(str[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void getAllParts(std::string s, std::vector<std::string> &partitions,
                     std::vector<std::vector<std::string>> &ans) {

        if (s.empty()) {
            ans.push_back(partitions);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            std::string part = s.substr(0, i+1);

            if (isPalindrome(part)) {
                partitions.push_back(part);
                getAllParts(s.substr(i+1), partitions, ans);
                partitions.pop_back();  //backtracking so that we can start with a fresh set of new partitions
            }
        }
    }

    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> partitions;
        getAllParts(s, partitions, ans);
        return ans;
    }

    void solution() {
        std::string s = "aab";
        std::cout << "Palindrome Partitioning O(n*2^n): \n";
        auto ans = partition(s);
        for (auto &p: ans) {
            std::cout << "{";
            for (auto &s: p) {
                std::cout << s << " ";
            }
            std::cout << "}\n";
        }
    }
};


#endif //LEETCODE_PALINDROMEPARTITIONING_H
