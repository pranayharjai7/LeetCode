#ifndef LEETCODE_AVLTREES_H
#define LEETCODE_AVLTREES_H

struct Node {
    int value;
    int height;
    Node *left;
    Node *right;

    explicit Node(int key) : value(key), height(1), left(nullptr), right(nullptr) {}
};

class AVLTrees {
public:
    void insertInAVLTree(Node* &root, int key) {
        if (!root) {
            root = new Node(key);
            return;
        }
        if (key <= root->value) {
            insertInAVLTree(root->left, key);
        } else {
            insertInAVLTree(root->right, key);
        }

        //update height

    }
};


#endif //LEETCODE_AVLTREES_H
