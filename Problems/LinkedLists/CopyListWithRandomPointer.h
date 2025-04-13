#ifndef LEETCODE_COPYLISTWITHRANDOMPOINTER_H
#define LEETCODE_COPYLISTWITHRANDOMPOINTER_H

#include <unordered_map>

class RandomNode {
public:
    int val;
    RandomNode* next;
    RandomNode* random;

    RandomNode(int _val): val(_val), next(nullptr), random(nullptr) {}
};

class CopyListWithRandomPointer {
public:
    RandomNode* copyRandomList(RandomNode* head) {  // just create an exact replica of linkedlist sent
        if (!head) return nullptr;

        std::unordered_map<RandomNode*, RandomNode*> uMap;  //map of old-new nodes

        RandomNode* newHead = new RandomNode(head->val);
        uMap.insert({head, newHead});   //or uMap[head] = newHead;
        RandomNode* newTemp = newHead;
        RandomNode* temp = head;

        while(temp->next) {
            temp = temp->next;
            RandomNode* newNode = new RandomNode(temp->val);
            newTemp->next = newNode;
            newTemp = newTemp->next;
            uMap.insert({temp, newTemp});
        }

        temp = head;
        newTemp = newHead;

        while (temp) {
            newTemp->random = uMap[temp->random];
            //temp->random returns the node which is pointed to by random of temp.
            // uMap[temp->random] find the value (node of newHead) corresponding to the key (temp->random)
            // newTemp->random now can point to the corresponding node of the newHead.
            temp = temp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};


#endif //LEETCODE_COPYLISTWITHRANDOMPOINTER_H
