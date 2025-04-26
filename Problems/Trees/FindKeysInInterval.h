#ifndef LEETCODE_FINDKEYSININTERVAL_H
#define LEETCODE_FINDKEYSININTERVAL_H


#include <vector>
#include "BinaryTrees.h"

class FindKeysInInterval {
public:
    void addKeysInInterval(Node *root, std::pair<int, int> &interval, std::vector<int> &ans) {
        if (!root) {
            return;
        }

        if (interval.first <= root->value && root->value <= interval.second) {
            ans.push_back(root->value);
            addKeysInInterval(root->left, interval, ans);
            addKeysInInterval(root->right, interval, ans);
        } else if (root->value < interval.first) {
            addKeysInInterval(root->right, interval, ans);
        } else {
            addKeysInInterval(root->left, interval, ans);
        }
    }

    std::vector<int> findKeysInInterval(Node *root, std::pair<int, int> &interval) {
        std::vector<int> ans;

        addKeysInInterval(root, interval, ans);
        return ans;
    }

    void solution() {
        std::vector<int> preOrderSeq = {5, 3, 2, -1, -1, 4, -1, -1, 8, -1, 10, -1, -1};
        BinaryTrees binaryTrees;
        int idx = 0;
        Node *root = binaryTrees.buildTree(preOrderSeq, idx);

        std::pair<int, int> interval = {4, 8};
        auto ans = findKeysInInterval(root, interval);

        std::cout << "Keys in the interval { " << interval.first << ", " << interval.second << "}: ";
        for (auto &a: ans) {
            std::cout << a << ", ";
        }
        std::cout << std::endl;
    }
};


#endif //LEETCODE_FINDKEYSININTERVAL_H
