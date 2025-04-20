#ifndef LEETCODE_SUBTREEOFANOTHERTREE_H
#define LEETCODE_SUBTREEOFANOTHERTREE_H


#include "BinaryTrees.h"

class SubtreeOfAnotherTree {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p || !q) {
            return p == q;
        }

        bool checkLeft = isSameTree(p->left, q->left);
        bool checkRight = isSameTree(p->right, q->right);

        return checkLeft && checkRight && (p->val == q->val);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root || !subRoot) {
            return root == subRoot;
        }

        if (root->val == subRoot->val && isSameTree(root, subRoot)) {
            return true;
        }

        bool foundInLeft = isSubtree(root->left, subRoot);
        if (foundInLeft) {
            return true;
        }

        return isSubtree(root->right, subRoot);
    }
};


#endif //LEETCODE_SUBTREEOFANOTHERTREE_H
