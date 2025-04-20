
#ifndef LEETCODE_DIAMETEROFTREE_H
#define LEETCODE_DIAMETEROFTREE_H


#include "BinaryTrees.h"

class DiameterOfTree {
private:
    int longest = 0;
public:
    int calcLongest(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int longestLeftLength = calcLongest(root->left);
        int longestRightLength = calcLongest(root->right);

        longest = std::max(longest, longestLeftLength + longestRightLength);

        return std::max(longestLeftLength, longestRightLength) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        calcLongest(root);
        return longest;
    }
};


#endif //LEETCODE_DIAMETEROFTREE_H
