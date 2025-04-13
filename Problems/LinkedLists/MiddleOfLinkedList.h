//
// Created by harjai on 31-Mar-25.
//

#ifndef LEETCODE_MIDDLEOFLINKEDLIST_H
#define LEETCODE_MIDDLEOFLINKEDLIST_H


#include "LinkedList.h"

class MiddleOfLinkedList {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while (temp) {
            temp = temp->next;
            size++;
        }

        int mid = size/2;
        temp = head;
        for (int i = 0; i < mid; ++i) {
            temp = temp->next;
        }

        return temp;
    }

    ListNode* middleNodeSlowFast(ListNode* head) {  //O(n) essentially O(n/2) as it skips 1 value
        ListNode* slow = head;      //update by 1
        ListNode* fast = head;      //update by 2

        while (fast && fast->next) {    //for even and odd number of nodes
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};


#endif //LEETCODE_MIDDLEOFLINKEDLIST_H
