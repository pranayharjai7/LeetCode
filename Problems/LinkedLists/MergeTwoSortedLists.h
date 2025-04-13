#ifndef LEETCODE_MERGETWOSORTEDLISTS_H
#define LEETCODE_MERGETWOSORTEDLISTS_H


#include "LinkedList.h"

class MergeTwoSortedLists {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
                curr = curr->next;
            }
        }

        if (list1) {
            curr->next = list1;
        }
        if (list2) {
            curr->next = list2;
        }

        curr = ans;
        ans = ans->next;
        delete curr;
        return ans;
    }

    ListNode* mergeTwoListsRec(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoListsRec(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoListsRec(list1, list2->next);
            return list2;
        }
    }
};


#endif //LEETCODE_MERGETWOSORTEDLISTS_H
