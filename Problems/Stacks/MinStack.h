#ifndef LEETCODE_MINSTACK_H
#define LEETCODE_MINSTACK_H

#include <stack>

class MinStack {
private:
    std::stack<std::pair<int, int>> stack;
public:
    MinStack() {
    }

    void push(int val) {
        if (stack.empty()) {
            stack.emplace(val, val);
            return;
        }
        stack.emplace(val, std::min(stack.top().second, val));
    }

    void pop() {
        stack.pop();
    }

    int top() {
        return stack.top().first;
    }

    int getMin() {
        return stack.top().second;
    }
};

#endif //LEETCODE_MINSTACK_H
