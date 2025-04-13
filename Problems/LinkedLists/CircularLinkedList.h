#ifndef LEETCODE_CIRCULARLINKEDLIST_H
#define LEETCODE_CIRCULARLINKEDLIST_H

#include "LinkedList.h"

class CircularList {
public:
    LinkNode *head;
    LinkNode *tail;

    CircularList() {
        head = tail = nullptr;
    }

    void insert_at_head(int val) {
        auto *node = new LinkNode(val);
        if (!head) {
            head = tail = node;
            tail->next = head;
            return;
        }

        node->next = head;
        head = node;
        tail->next = head;
    }

    void insert_at_tail(int val) {
        auto *node = new LinkNode(val);
        if (!head) {
            head = tail = node;
            tail->next = head;
            return;
        }

        node->next = head;
        tail->next = node;
        tail = node;
    }

    void delete_at_head() {
        if (!head) {
            std::cout << "deleting from empty list";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        auto *temp = head;

        tail->next = head->next;
        head = head->next;
        temp->next = nullptr;

        delete temp;
    }

    void delete_at_tail() {
        if (!head) {
            std::cout << "deleting from empty list";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        auto *temp = tail;

        auto *prev = head;  //to find previous node of tail
        while (prev->next != tail) {
            prev = prev->next;
        }

        tail = prev;
        tail->next = head;
        temp->next = nullptr;
        delete temp;
    }

    void print() {
        if (!head) return;

        std::cout << head->data << " -> ";
        LinkNode *temp = head->next;
        while (temp != head) {      //temp will never be null in circular list
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "(front)\n";
    }
};

class CircularLinkedList {
public:
    void solution() {
        std::cout << "Circular Linked List:\n";
        CircularList cll;
        cll.insert_at_head(1);
        cll.insert_at_head(2);
        cll.insert_at_head(3);
        cll.insert_at_head(4);
        cll.print();

        cll.insert_at_tail(10);
        cll.insert_at_tail(20);
        cll.insert_at_tail(30);
        cll.insert_at_tail(40);
        cll.print();

        cll.delete_at_head();
        cll.delete_at_head();
        cll.print();

        cll.delete_at_tail();
        cll.delete_at_tail();
        cll.print();
    }
};


#endif //LEETCODE_CIRCULARLINKEDLIST_H
