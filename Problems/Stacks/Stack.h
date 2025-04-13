#ifndef LEETCODE_STACK_H
#define LEETCODE_STACK_H


#include <vector>
#include <iostream>
#include <list>
#include <stack>

class StackVector {
private:
    std::vector<int> stackVec;
public:
    void push(int val) {
        stackVec.push_back(val);
    }

    void pop() {
        stackVec.pop_back();
    }

    int top() {
        return stackVec[stackVec.size() - 1];
    }

    bool isEmpty() {
        return stackVec.size() == 0;
    }

};

class StackLinkedList {
private:
    std::list<int> stackLinkedList;

public:
    void push(int val) {
        stackLinkedList.push_front(val);
    }

    void pop() {
        stackLinkedList.pop_front();
    }

    int top() {
        return stackLinkedList.front();
    }

    bool isEmpty() {
        return stackLinkedList.empty();
    }
};

class Stack {
public:
    void solution() {
        std::cout << "Stack\n";
        std::cout << "using vectors: \n";
        StackVector s;
        s.push(10);
        s.push(20);
        s.push(30);

        while (!s.isEmpty()) {
            std::cout << s.top() << " ";
            s.pop();
        }

        std::cout << std::endl;

        std::cout << "using LinkedList: \n";
        StackLinkedList sll;
        sll.push(10);
        sll.push(20);
        sll.push(30);

        while (!sll.isEmpty()) {
            std::cout << sll.top() << " ";
            sll.pop();
        }

        std::cout << std::endl;

        std::cout << "using Stack: \n";
        std::stack<int> stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);

        while (!stack.empty()) {
            std::cout << stack.top() << " ";
            stack.pop();
        }

        std::cout << std::endl;

    }
};


#endif //LEETCODE_STACK_H
