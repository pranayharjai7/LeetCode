#ifndef LEETCODE_FIRSTUNIQUECHARACTERINSTRING_H
#define LEETCODE_FIRSTUNIQUECHARACTERINSTRING_H

#include <iostream>
#include <set>
#include <unordered_map>
#include <queue>

class FirstUniqueCharacterInString {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> map;  //map of characters of string and their frequencies
        std::queue<int> q;  //queue for unique elements
        for (int i = 0; i < s.size(); ++i) {
            if (map.find(s[i]) == map.end()) {
                map[s[i]] = 1;
                q.push(i);
            } else {
                map[s[i]]++;
            }

            while (!q.empty() && map[s[q.front()]] > 1) {
                q.pop();
            }
        }
        if (!q.empty()) return q.front();
        return -1;
    }

    int firstUniqChar2(std::string s) {
        int n = s.length();
        int count[26] = {0};
        for(int i =0;i<n;i++){
            count[s[i] - 'a']++;
        }
        for(int i =0;i<n;i++){
            if(count[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }

    void solution() {
        std::string s = "Aabc";
        std::cout << "First Unique Character in string " << s << ": " << firstUniqChar(s) << std::endl;
        std::cout << "First Unique Character in string " << s << ": " << firstUniqChar2(s) << std::endl;
    }
};


#endif //LEETCODE_FIRSTUNIQUECHARACTERINSTRING_H
