#ifndef LEETCODE_QUEUE_H
#define LEETCODE_QUEUE_H

#include <list>
#include <iostream>

class NodeQ {
public:
    int data;
    NodeQ *next;

    NodeQ(int data) : data(data), next(nullptr) {}
};

class Queue {
private:
    NodeQ *head;
    NodeQ *tail;
public:
    Queue() {
        head = tail = nullptr;
    }

    void push(int val) {
        NodeQ *newNode = new NodeQ(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void pop() {
        if (!head) {
            std::cout << "Empty queue!";
            return;
        }
        auto temp = head;
        head = head->next;
        delete temp;
    }

    int front() {
        if (!head) {
            std::cout << "Empty queue!";
            return -1;
        }

        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }
};


#endif //LEETCODE_QUEUE_H
