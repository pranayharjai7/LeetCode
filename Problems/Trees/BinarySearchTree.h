#ifndef LEETCODE_BINARYSEARCHTREE_H
#define LEETCODE_BINARYSEARCHTREE_H

#include <iostream>
#include "BinaryTrees.h"

class BinarySearchTree {
public:
    void insertBST(Node* &root, int key) {
        if (!root) {
            root = new Node(key);
            return;
        }

        Node *temp = root;
        while (temp) {
            if (key <= temp->value) {
                if (!temp->left) {
                    temp->left = new Node(key);
                    break;
                }
                temp = temp->left;
            } else {
                if (!temp->right) {
                    temp->right = new Node(key);
                    break;
                }
                temp = temp->right;
            }
        }
    }

    void insertBSTRec(Node* &root, int key) {
        if (!root) {
            root = new Node(key);
            return;
        }

        if (key <= root->value) {
            insertBSTRec(root->left, key);
        } else {
            insertBSTRec(root->right, key);
        }
    }

    void inorderTraversal(Node* root) {
        if (!root) return;

        inorderTraversal(root->left);
        std::cout << root->value << " ";
        inorderTraversal(root->right);
    }

    void preorderTraversal(Node* root) {
        if (!root) return;

        std::cout << root->value << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    void postorderTraversal(Node* root) {
        if (!root) return;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->value << " ";
    }

    Node* searchInBinarySearchTree(Node* root, int target) {
        if (!root) return nullptr;

        if (root->value == target) return root;
        if (root->value > target) return searchInBinarySearchTree(root->left, target);
        return searchInBinarySearchTree(root->right, target);
    }

    void solution() {
        std::cout << "Binary Search Tree: ";
        Node *root = nullptr;
        insertBSTRec(root, 5);
        insertBSTRec(root, 1);
        insertBSTRec(root, 3);
        insertBSTRec(root, 2);
        insertBSTRec(root, 10);
        insertBSTRec(root, 8);
        insertBSTRec(root, 12);
        insertBSTRec(root, 13);
        insertBSTRec(root, 14);

        std::cout << std::endl << "inorderTraversal: ";
        inorderTraversal(root);
        std::cout << std::endl << "preorderTraversal: ";
        preorderTraversal(root);
        std::cout << std::endl << "postorderTraversal: ";
        postorderTraversal(root);
        std::cout << std::endl;

        Node* ans = searchInBinarySearchTree(root, 8);
        std::cout << "Binary Search tree element found: " <<  (ans?ans->value:-1) << std::endl;
    }
};


#endif //LEETCODE_BINARYSEARCHTREE_H
