#ifndef LEETCODE_HEIGHTOFTREE_H
#define LEETCODE_HEIGHTOFTREE_H


#include "BinaryTrees.h"

class HeightOfTree {
public:
    int height(Node *root) {
        if (!root) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + std::max(leftHeight, rightHeight);
    }

    int count(Node* root) {
        if (!root) {
            return 0;
        }

        return 1 + count(root->left) + count(root->right);
    }

    int sum(Node* root) {
        if (!root) {
            return 0;
        }

        int leftSum = sum(root->left);
        int rightSum = sum(root->right);

        return root->value + leftSum + rightSum;
    }

    void solution() {
        BinaryTrees binaryTrees;
        std::vector<int> preOrderSeq = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
        int idx = 0;
        Node* root = binaryTrees.buildTree(preOrderSeq, idx);
        std::cout << "Height of Binary tree: " << height(root) << std::endl;
        std::cout << "Number of Nodes in Binary tree: " << count(root) << std::endl;
        std::cout << "Sum of Nodes in Binary tree: " << sum(root) << std::endl;
    }
};


#endif //LEETCODE_HEIGHTOFTREE_H
