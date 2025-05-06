#ifndef LEETCODE_PUSHDOMINOES_H
#define LEETCODE_PUSHDOMINOES_H


#include <string>

enum DIRECTION {
    DOT = 0,
    LEFT = 1,
    RIGHT = 2
};

class PushDominoes {
public:
    //when we find an L or R:
    //  cases:
    //  we found an L:
    //  1. we have no L or R before that (this means mark all L before this L)
    //  2. we had an L before that (this means mark all L upto that L)
    //  3. we had an R before that (this gives 2 situations)
    //      3.1 we have even number of "." between them (this means first half would be R, second half would be L)
    //      3.2 we have odd number of "." between them (this means first half would be R, mid would be . and second half would be L)
    //
    std::string pushDominoes(std::string dominoes) {
        std::string ans = "";
        DIRECTION markLast = DOT;  //0(.) 1(L) 2(R)
        int lastIndex = 0;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] == 'L') {
                if (markLast == DOT || markLast == LEFT) {
                    ans.append(i - lastIndex, 'L');
                } else {
                    int len = i - lastIndex - 1;
                    int half = len / 2;
                    ans.append(half, 'R');
                    if (len % 2 == 0) ans.append(1, '.');
                    else  {
                        ans.append(1, 'R');
                        ans.append(1, 'L');
                    }
                    ans.append(half, 'L');
                }
                ans.append(1, 'L');
                markLast = LEFT;
                lastIndex = i + 1;
            } else if (dominoes[i] == 'R') {
                if (markLast == DOT || markLast == LEFT) {
                    ans.append(i - lastIndex, '.');
                } else {
                    ans.append(i - lastIndex, 'R');
                }
                ans.append(1, 'R');
                markLast = RIGHT;
                lastIndex = i + 1;
            }
        }

        if (lastIndex < dominoes.size()) {
            if (markLast == RIGHT) {
                ans.append(dominoes.size() - lastIndex, 'R');
            } else {
                ans.append(dominoes.size() - lastIndex, '.');
            }
        }

        return ans;
    }
};


#endif //LEETCODE_PUSHDOMINOES_H
