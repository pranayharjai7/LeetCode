//
// Created by harjai on 13-Jul-25.
//

#ifndef STRINGREVISION_H
#define STRINGREVISION_H
#include <iostream>
#include <string>


class StringRevision {
public:
    bool isPalindrome(std::string &s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] == ' ') {
                start++;
                continue;
            }
            if (s[end] == ' ') {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    int lengthOfLongestSubstring(std::string s) {
        std::string ans = "";
        std::string temp = "";
        std::unordered_set<char> uSet;
        for (int i = 0; i < s.size(); i++) {
            if (uSet.find(s[i]) == uSet.end()) {
                temp += s[i];
                uSet.insert(s[i]);
            } else {
                ans = (temp.size() > ans.size()) ? temp : ans;
                uSet.clear();
                uSet.insert(s[i]);
                temp = s[i];
            }
        }

        ans = (temp.size() > ans.size()) ? temp : ans;
        return ans.size();
    }


    unsigned int calc_list(std::vector<unsigned int> &X, bool isAnd) {
        if (X.empty()) return 0;
        unsigned int ans = X[0];
        for (int i = 1; i < X.size(); i++) {
            if (isAnd) {
                ans = ans & X[i];
            } else {
                ans = ans ^ X[i];
            }

        }
        return ans;
    }


    unsigned int and_list(std::vector<unsigned int> &X) {
        return calc_list(X, true);
    }

    unsigned int xor_list(std::vector<unsigned int> &X) {
        return calc_list(X, false);
    }

    unsigned int f(std::vector<unsigned int>& X) {
        if (X.empty()) return 0;

        const size_t N = X.size();
        std::vector<unsigned int> sub_xors;
        sub_xors.reserve(N * (N + 1) / 2); // number of nonempty contiguous sublists

        for (size_t start = 0; start < N; ++start) {
            for (size_t end = start; end < N; ++end) {
                // extract the contiguous sublist X[start..end]
                std::vector<unsigned int> sub(X.begin() + start, X.begin() + end + 1);
                // XOR of that sublist
                sub_xors.push_back(xor_list(sub));
            }
        }

        // AND of all the sublist XORs
        return and_list(sub_xors);
    }

    void fun() {
        std::vector<unsigned int> X = {3};
        auto ans = f(X);
        std::cout << ans;
    }


    void solution() {
        std::string s = " Hello olleh  ";
        std::cout << "Is " << s << " a palindrome?: " << isPalindrome(s) << std::endl;
        fun();
    }
};


#endif //STRINGREVISION_H
