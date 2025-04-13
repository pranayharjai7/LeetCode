#ifndef LEETCODE_STRINGMANIPULATION_H
#define LEETCODE_STRINGMANIPULATION_H


#include <string>
#include <iostream>
#include <algorithm>

class StringManipulation {
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

    std::string removeOccurrences(std::string s, std::string part) {
        while (s.find(part) != std::string::npos) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }

    bool checkPermutationInString(std::string s1, std::string s2) {
        int freq[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            int idx = s1[i] - 'a';
            freq[idx]++;
        }
        int windowSize = s1.length();

        for (int i = 0; i < s2.length(); ++i) {

        }
        return false;
    }

    std::string stringReversal(std::string str) {
        for (int i = 0; i < str.length() / 2; ++i) {
            std::swap(str[i], str[str.length() - i - 1]);
        }
        return str;
    }

    void reverseWordsInSameString(std::string &s) {
        while (!isalnum(s[0])) {
            s.erase(0, 1); //no need for i++ because erase already shifts the string
        }
        std::reverse(s.begin(), s.end());
        while (!isalnum(s[0])) {
            s.erase(0, 1); //no need for i++ because erase already shifts the string
        }
        int startOfWord = 0;
        int endOfWord = startOfWord;
        int spaceCount = 0;
        while (startOfWord < s.length()) {
            if (spaceCount > 1) {
                s.erase(startOfWord - 1, 1);
                spaceCount--;
                startOfWord--;
                endOfWord--;
            }
            if (s[startOfWord] == ' ') {
                spaceCount++;
                startOfWord++;
                endOfWord++;
                continue;
            }
            while (s[endOfWord] != ' ' && endOfWord < s.length()) {
                endOfWord++;
            }
            std::reverse(s.begin()+startOfWord, s.begin()+endOfWord);
            startOfWord = endOfWord;
            spaceCount = 0;
        }
    }

    void solution() {
        std::string str = "Hello 1!@$#$!#1 olleh";
        std::cout << "Is " << str << " Palindrome? " << isPalindrome(str) << std::endl;

        std::string str2 = "daabcbaabcbc";
        std::string part = "abc";
        std::cout << "Removed occurrences of " << part << " in " << str2 << ": ";
        std::cout << removeOccurrences(str2, part) << std::endl;

        std::string str3 = "Hello world";
        std::cout << "Reverse of " << str3 << ": " << stringReversal(str3) << std::endl;

        std::string str4 = "the sky is blue";
        std::cout << "Reverse words of \"" << str4 << "\" in the same string: \"";
        reverseWordsInSameString(str4);
        std::cout << str4 << "\"\n";
    }
};


#endif //LEETCODE_STRINGMANIPULATION_H
