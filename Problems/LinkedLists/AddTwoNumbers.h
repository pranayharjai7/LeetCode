#ifndef LEETCODE_ADDTWONUMBERS_H
#define LEETCODE_ADDTWONUMBERS_H

#include <iostream>
#include <valarray>
#include "LinkedList.h"

class AddTwoNumbers {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *current = dummyHead;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }

    void solution() {
        ListNode* lb = new ListNode(3);
        ListNode* la = new ListNode(4, lb);
        ListNode* l1 = new ListNode(2, la);

        ListNode* lB = new ListNode(4);
        ListNode* lA = new ListNode(6, lB);
        ListNode* l2 = new ListNode(5, lA);

        auto* listAns = addTwoNumbers(l1, l2);
        int num1 = 0;
        int i = 0;
        while(listAns) {
            num1 += (listAns->val)*(std::pow(10,i));
            listAns = listAns->next;
            i++;
        }
        std::cout << "Add two numbers in Linked List: " << num1 << std::endl;
    }
};


#endif //LEETCODE_ADDTWONUMBERS_H
