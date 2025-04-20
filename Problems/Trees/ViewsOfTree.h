#ifndef LEETCODE_VIEWSOFTREE_H
#define LEETCODE_VIEWSOFTREE_H


#include <vector>
#include <map>
#include "BinaryTrees.h"

class ViewsOfTree {
public:
    std::vector<int> topViewOfBinaryTree(Node *root) {  //just use level order traversal
        std::queue<std::pair<Node *, int>> q;   //tracks the node with its horizontal distance
        q.emplace(root, 0);

        //a map track the first Node in a given vertical distance..
        // meaning that if a node has horizontal distance 0 and is added to the map,
        // no other node with horizontal distance 0 should be added.
        std::map<int, Node *> map;

        while (!q.empty()) {
            auto currPair = q.front();
            q.pop();

            if (map.find(currPair.second) == map.end()) {
                map[currPair.second] = currPair.first;
            }

            if (currPair.first->left) {
                q.emplace(currPair.first->left, currPair.second - 1);
            }
            if (currPair.first->right) {
                q.emplace(currPair.first->right, currPair.second + 1);
            }
        }

        std::vector<int> ans;
        for (auto &p: map) {
            ans.push_back(p.second->value);
        }
        return ans;
    }

    std::vector<int> bottomViewOfBinaryTree(Node *root) {   //almost same as top view
        std::queue<std::pair<Node *, int>> q;
        q.emplace(root, 0);

        std::map<int, Node *> map;

        while (!q.empty()) {
            auto currPair = q.front();
            q.pop();

            //just replace the previous Node in case of same horizontal distance
            map[currPair.second] = currPair.first;

            if (currPair.first->left) {
                q.emplace(currPair.first->left, currPair.second - 1);
            }
            if (currPair.first->right) {
                q.emplace(currPair.first->right, currPair.second + 1);
            }
        }

        std::vector<int> ans;
        for (auto &p: map) {
            ans.push_back(p.second->value);
        }
        return ans;
    }

    std::vector<int> rightViewOfBinaryTree(Node *root) {   //almost same as top view
        std::queue<std::pair<Node *, int>> q;   //int is vertical distance this time.
        q.emplace(root, 0);

        std::map<int, Node *> map;

        while (!q.empty()) {
            auto currPair = q.front();
            q.pop();

            //just replace the previous Node in case of same vertical distance
            map[currPair.second] = currPair.first;

            if (currPair.first->left) {
                q.emplace(currPair.first->left, currPair.second + 1);
            }
            if (currPair.first->right) {
                q.emplace(currPair.first->right, currPair.second + 1);
            }
        }

        std::vector<int> ans;
        for (auto &p: map) {
            ans.push_back(p.second->value);
        }
        return ans;
    }

    void solution() {
        std::vector<int> preOrderSeq = {1, 2, -1, -1, 3, 4, 6, 7, -1, -1, 8, -1, -1, -1, 5, -1, -1};
        BinaryTrees binaryTrees;
        int idx = 0;
        Node *root = binaryTrees.buildTree(preOrderSeq, idx);

        std::cout << "Top view of binary tree: ";
        auto ans = topViewOfBinaryTree(root);
        for (auto &i: ans) {
            std::cout << i << ", ";
        }
        std::cout << "\nBottom view of binary tree: ";
        auto ans2 = bottomViewOfBinaryTree(root);
        for (auto &i: ans2) {
            std::cout << i << ", ";
        }

        std::cout << "\nRight view of binary tree: ";
        auto ans3 = rightViewOfBinaryTree(root);
        for (auto &i: ans3) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }
};


#endif //LEETCODE_VIEWSOFTREE_H
