#ifndef LEETCODE_QUEUEUSINGSTACKS_H
#define LEETCODE_QUEUEUSINGSTACKS_H

#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> s1;
    std::stack<int> s2;
public:
    MyQueue() {
    }

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

class QueueUsingStacks {
public:
    void solution() {
        std::cout << "\nImplementing Queue using 2 stacks:\n";
        MyQueue myQueue;
        myQueue.push(1);
        myQueue.push(2);
        myQueue.push(3);
        myQueue.push(4);
        std::cout << "Queue Front: " << myQueue.peek() << std::endl;

        myQueue.pop();
        std::cout << "Queue Front after popping: " << myQueue.peek() << std::endl;
    }
};


#endif //LEETCODE_QUEUEUSINGSTACKS_H
