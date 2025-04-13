#ifndef LEETCODE_VALIDPARENTHESIS_H
#define LEETCODE_VALIDPARENTHESIS_H

#include <string>
#include <stack>

class ValidParenthesis {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;

        for (char &ch: s) {
            switch (ch) {
                case '{':
                case '(':
                case '[':
                    stack.push(ch);
                    break;
                case '}':
                    if (!stack.empty() && stack.top() == '{') stack.pop();
                    else return false;
                    break;
                case ')':
                    if (!stack.empty() && stack.top() == '(') stack.pop();
                    else return false;
                    break;
                case ']':
                    if (!stack.empty() && stack.top() == '[') stack.pop();
                    else return false;
                    break;
                default:
                    return false;
            }
        }

        return stack.empty();
    }

    bool isValid2(std::string s) {
        std::stack<char> stack;

        for (char &ch: s) {
            if (ch == '(') stack.push(')');
            else if (ch == '{') stack.push('}');
            else if (ch == '[') stack.push(']');
            else {
                if (stack.empty() || stack.top() != ch) {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.empty();
    }
};


#endif //LEETCODE_VALIDPARENTHESIS_H
