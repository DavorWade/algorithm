#include <stdlib.h>
#include <stdio.h>
#include <vector>

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
    * @param root: The root of binary tree
    * @return root of new tree
    */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
        TreeNode *new_root = nullptr;

        return dfs(root, new_root);
    }

    TreeNode* dfs(TreeNode *root, TreeNode *curr) {
        if (root == nullptr) return nullptr;

        curr = new TreeNode(root->val);

        if (root->left != nullptr) curr->left = dfs(root->left, curr->left);
        if (root->right != nullptr) curr->right = dfs(root->right, curr->right);

        return curr;
    }
};
