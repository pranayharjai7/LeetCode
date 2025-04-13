#ifndef LEETCODE_FLATTENMULTILEVELDOUBLYLINKEDLIST_H
#define LEETCODE_FLATTENMULTILEVELDOUBLYLINKEDLIST_H

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class FlattenMultiLevelDoublyLinkedList {
public:

    Node* flattenRec(Node* parent, Node* curr) {
        curr->prev = parent;

        while (curr->next) {
            if (curr->child) {
                curr = flattenRec(curr, curr->child);
            } else {
                curr = curr->next;
            }
        }

        if (curr->child) {
            curr = flattenRec(curr, curr->child);
        } else {
            if (parent->next) {
                curr->next = parent->next;
                parent->next->prev = curr;
            } else {
                curr->next = nullptr;
            }
            parent->next = parent->child;
            parent->child = nullptr;
        }

        return curr->next;
    }

    Node* flattenRec2(Node* head) {
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* next = curr->next;
                curr->next = flattenRec2(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;
            } else {
                curr = curr->next;
            }
        }
    }

    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }

        Node* curr = head;
        while (curr) {
            if (curr->child) {
                //flatten the child node
                Node* next = curr->next;
                curr->next = flattenRec2(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;

                //find tail
                while (curr->next) {
                    curr = curr->next;
                }
                //attach tail to next
                if (next) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};


#endif //LEETCODE_FLATTENMULTILEVELDOUBLYLINKEDLIST_H
