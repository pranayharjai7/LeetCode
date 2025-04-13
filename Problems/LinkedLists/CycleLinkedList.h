#ifndef LEETCODE_CYCLELINKEDLIST_H
#define LEETCODE_CYCLELINKEDLIST_H


#include "LinkedList.h"

class CycleLinkedList {
public:
    bool hasCycle(ListNode *head) { //slow fast pointer approach
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast && fast->next) {     //detect cycle
            slow = slow->next;          //(+1)
            fast = fast->next->next;    //((+2)
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) {
            return nullptr;
        }

        slow = head;
        while(slow != fast) {       //detect starting point of cycle
            slow = slow->next; //(+1)
            fast = fast->next; //(+1)
        }

        return slow;    // or fast
    }

    ListNode *removeCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast && fast->next) {     //detect cycle
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) {
            return nullptr;
        }

        slow = head;
        ListNode* prev = nullptr;
        while(slow != fast) {       //detect starting point of cycle
            slow = slow->next;
            prev = fast;        //stores old value of fast. (previous of fast)
            fast = fast->next;
        }

        prev->next = nullptr;   //breaks the cycle
    }
};


#endif //LEETCODE_CYCLELINKEDLIST_H
