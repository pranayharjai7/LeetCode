#ifndef LEETCODE_REVERSELINKEDLIST_H
#define LEETCODE_REVERSELINKEDLIST_H

#include "LinkedList.h"

class ReverseLinkedList {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};


#endif //LEETCODE_REVERSELINKEDLIST_H
