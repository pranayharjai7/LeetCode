#ifndef LEETCODE_STACKUSINGQUEUES_H
#define LEETCODE_STACKUSINGQUEUES_H

#include <queue>
#include <iostream>

class MyStack {
    std::queue<int> q1;
    std::queue<int> q2;
public:
    MyStack() {

    }

    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

class StackUsingQueues {
public:
    void solution() {
        std::cout << "\nImplementing Stack using 2 queues:\n";
        MyStack myStack;
        myStack.push(1);
        myStack.push(2);
        myStack.push(3);
        myStack.push(4);
        std::cout << "Stack Top: " << myStack.top() << std::endl;

        myStack.pop();
        std::cout << "Stack Top after popping: " << myStack.top() << std::endl;
    }
};


#endif //LEETCODE_STACKUSINGQUEUES_H
