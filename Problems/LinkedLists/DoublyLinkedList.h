#ifndef LEETCODE_DOUBLYLINKEDLIST_H
#define LEETCODE_DOUBLYLINKEDLIST_H

#include <iostream>

class DoubleLinkNode {
public:

    int data;
    DoubleLinkNode *next;
    DoubleLinkNode *prev;

    DoubleLinkNode(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyList {
    DoubleLinkNode *head;
    DoubleLinkNode *tail;

public:
    DoublyList() {
        head = tail = nullptr;
    }

    void push_front(int data) {
        DoubleLinkNode *node = new DoubleLinkNode(data);
        if (!head) {
            head = tail = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    void push_back(int data) {
        DoubleLinkNode *node = new DoubleLinkNode(data);
        if (!head) {
            head = tail = node;
            return;
        }

        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void pop_front() {
        if (!head) {
            std::cout << "Removing from an empty list!";
            return;
        }
        auto *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!head) {
            std::cout << "Removing from an empty list!";
            return;
        }

        auto *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }

    void print() {
        DoubleLinkNode *temp = head;
        while (temp) {
            std::cout << temp->data << " <=> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

class DoublyLinkedList {
public:
    void solution() {
        std::cout << "Doubly Linked List:\n";
        DoublyList dll;
        dll.push_front(1);
        dll.push_front(2);
        dll.push_back(3);
        dll.push_back(4);
        dll.push_front(10);
        dll.push_front(20);
        dll.push_back(30);
        dll.push_back(40);
        dll.print();

        dll.pop_front();
        dll.pop_back();

        dll.print();
    }
};


#endif //LEETCODE_DOUBLYLINKEDLIST_H
