#ifndef LEETCODE_KTHLEVELOFTREE_H
#define LEETCODE_KTHLEVELOFTREE_H


#include <vector>
#include "BinaryTrees.h"

class KthLevelOfTree {
public:
    std::vector<int> kthLevelOfTree(Node *root, int k) {
        std::queue<std::pair<Node *, int>> q;
        q.emplace(root, 1);
        std::vector<int> ans;
        while (!q.empty()) {
            auto currPair = q.front();
            q.pop();

            if (currPair.second > k) {
                continue;
            }
            if (currPair.second == k) {
                ans.push_back(currPair.first->value);
                continue;
            }

            if (currPair.first->left) {
                q.emplace(currPair.first->left, currPair.second + 1);
            }
            if (currPair.first->right) {
                q.emplace(currPair.first->right, currPair.second + 1);
            }
        }

        return ans;
    }

    void kthLevelOfTreeRec(Node *root, int k) {
        if (!root) {
            return;
        }

        if (k == 1) {
            std::cout << root->value << ", ";
            return;
        }

        kthLevelOfTreeRec(root->left, k-1);
        kthLevelOfTreeRec(root->right, k-1);
    }

    void solution() {
        std::vector<int> preOrderSeq = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
        BinaryTrees binaryTrees;
        int idx = 0;
        Node *root = binaryTrees.buildTree(preOrderSeq, idx);

        std::cout << "Kth level of binary tree: ";
        auto ans = kthLevelOfTree(root, 3);
        for (auto &i: ans) {
            std::cout << i << ", ";
        }
        std::cout << "\nKth level of binary tree Recursive: ";
        kthLevelOfTreeRec(root, 3);
        std::cout << std::endl;
    }
};


#endif //LEETCODE_KTHLEVELOFTREE_H
