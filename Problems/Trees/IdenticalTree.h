//
// Created by harjai on 19-Apr-25.
//

#ifndef LEETCODE_IDENTICALTREE_H
#define LEETCODE_IDENTICALTREE_H

#include "BinaryTrees.h"

class IdenticalTree {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p || !q) {
            return p == q;
        }

        bool checkLeft = isSameTree(p->left, q->left);
        bool checkRight = isSameTree(p->right, q->right);

        return checkLeft && checkRight && (p->val == q->val);
    }
};


#endif //LEETCODE_IDENTICALTREE_H
