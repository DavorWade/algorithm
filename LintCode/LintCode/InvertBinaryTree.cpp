#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
    * @param root: a TreeNode, the root of the binary tree
    * @return: nothing
    */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if (root == nullptr) {
            return;
        }

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *tree = q.front();
            q.pop();
            TreeNode *l = tree->left;
            tree->left = tree->right;
            tree->right = l;

            if (tree->left != nullptr) q.push(tree->left);
            if (tree->right != nullptr) q.push(tree->right);
        }
    }
};

// recursion
//class Solution {
//public:
//    /**
//    * @param root: a TreeNode, the root of the binary tree
//    * @return: nothing
//    */
//    void invertBinaryTree(TreeNode *root) {
//        // write your code here
//        if (root == nullptr) {
//            return;
//        }
//
//        queue<TreeNode *> q;
//        q.push(root);
//        while (!q.empty()) {
//            TreeNode *tree = q.front();q.pop();
//            TreeNode *l = tree->left;
//            tree->left = tree->right;
//            tree->right = l;
//
//            if (tree->left != nullptr) q.push(tree->left);
//            if (tree->right != nullptr) q.push(tree->right);
//        }
//
//    }
//};
