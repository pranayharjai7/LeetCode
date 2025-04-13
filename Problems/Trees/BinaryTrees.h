#ifndef LEETCODE_BINARYTREES_H
#define LEETCODE_BINARYTREES_H

#include <vector>
#include <iostream>
#include <queue>

//struct Node {
//    int value;
//    Node *left;
//    Node *right;
//
//    explicit Node(int key) : value(key), left(nullptr), right(nullptr) {}
//};

class Node {
public:
    int value;
    Node *left;
    Node *right;

    Node(int key) : value(key), left(nullptr), right(nullptr) {}
};

class BinaryTrees { //hierarchical DataStructure
public:

    Node *buildTree(std::vector<int> &preOrderSeq, int &idx) {
        if (preOrderSeq[idx] == -1) {
            return nullptr;
        }
        Node *root = new Node(preOrderSeq[idx]);

        root->left = buildTree(preOrderSeq, ++idx);
        root->right = buildTree(preOrderSeq, ++idx);

        return root;
    }

    void preorderTraversal(Node* root) {    //DFS
        if (!root) return;

        std::cout << root->value << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    void inorderTraversal(Node* root) {     //DFS
        if (!root) return;

        inorderTraversal(root->left);
        std::cout << root->value << " ";
        inorderTraversal(root->right);
    }

    void postorderTraversal(Node* root) {   //DFS
        if (!root) return;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->value << " ";
    }

    void levelOrderTraversal(Node* root) {  //iterative.. (using BFS) => use queue
        if (!root) return;
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            std::cout << curr->value << " ";

            //for each neighbors, i.e. left and right.. push into queue if not null
            if (curr->left) {           //neighbor 1
                q.push(curr->left);
            }
            if (curr->right) {          //neighbor 2
                q.push(curr->right);
            }

        }
    }

    void solution() {
        std::cout << "Binary trees:\n";
        std::vector<int> preOrderSequence = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
        std::cout << "Build a binary tree: ";
        int idx = 0;
        Node *root = buildTree(preOrderSequence, idx);  //O(n)
        preorderTraversal(root);
        std::cout << "\nPre order traversal: ";
        preorderTraversal(root);                //O(n)
        std::cout << "\nIn order traversal: ";
        inorderTraversal(root);                 //O(n)
        std::cout << "\nPost order traversal: ";
        postorderTraversal(root);               //O(n)
        std::cout << "\nLevel order traversal: ";
        levelOrderTraversal(root);               //O(n)
    }
};


#endif //LEETCODE_BINARYTREES_H
