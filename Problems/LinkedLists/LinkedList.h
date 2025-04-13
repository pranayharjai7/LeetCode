#ifndef LEETCODE_LINKEDLIST_H
#define LEETCODE_LINKEDLIST_H

#include <cstdlib>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkNode {
public:
    int data;
    LinkNode *next;

    LinkNode(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    LinkNode *head;
    LinkNode *tail;

public:
    LinkedList() {
        head = tail = nullptr;
    }

    void push_front(int val) {  //O(1)
        //Node n(val); -> dont use static implementation (it will destroy after function call finishes)
        LinkNode* newNode = new LinkNode(val);  //allocates the memory dynamically
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {   //if using tail O(1), if using head only, O(n)
        LinkNode* newNode = new LinkNode(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {  //O(1)
        //dynamic deletion needed because they were allocated dynamically
        if (!head) {
            std::cout << "LinkedList is empty!";
            return;
        }

        LinkNode* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    void pop_back() {   //O(n)
        if (!head) {
            std::cout << "LinkedList is empty!" << std::endl;
            return;
        }
        LinkNode* temp = head;

        while (temp->next != tail) {
            temp = temp->next;
        }

        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos) {     //O(n)
        if (pos < 0) {
            std::cout << "Invalid pos!" << std::endl;
            return;
        }

        if (pos == 0) {
            push_front(val);
            return;
        }

        auto temp = head;
        for (int i = 0; i < pos-1; ++i) {
            if (!temp) {
                std::cout << "Invalid pos!" << std::endl;
                return;
            }
            temp = temp->next;
        }

        auto newNode = new LinkNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key) {   //O(n)
        LinkNode* temp = head;
        int idx = 0;
        while (temp) {
            if (temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }

        return -1;
    }

    void print() {  //O(n)
        LinkNode* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void solution() {
        std::cout << "Linked list: \n";
        this->push_front(1);
        this->push_front(2);
        this->push_front(3);
        this->print();
        this->push_back(10);
        this->push_back(20);
        this->push_back(30);
        this->print();
        this->pop_front();
        this->print();
        this->pop_back();
        this->print();
        this->insert(4, 2);
        this->print();

        std::cout << "Search element 4: " << this->search(4) << std::endl;
    }
};


#endif //LEETCODE_LINKEDLIST_H
