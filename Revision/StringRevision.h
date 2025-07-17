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

    void solution() {
        std::string s = " Hello olleh  ";
        std::cout << "Is " << s << " a palindrome?: " << isPalindrome(s) << std::endl;
    }
};


#endif //STRINGREVISION_H
