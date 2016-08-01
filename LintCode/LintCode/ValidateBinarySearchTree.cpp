#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
    * @param root: The root of binary tree.
    * @return: True if the binary tree is BST, or false
    */
    bool isValidBST(TreeNode *root) {
        // write your code here
        return isValid(root, INT_MIN);
    }

    bool isValid(TreeNode *root, int min_val) {
        if (root == nullptr) return true;

        if (root->right == nullptr) {
            if (root->left != nullptr) {
                if (root->left->val >= root->val || root->left->val <= min_val) return false;
                else return isValid(root->left, min_val); //left subtree: min_val = min_val
            }
            else {
                return true;
            }
        }

        if (root->left == nullptr) {
            if (root->right != nullptr) {
                if (root->val >= root->right->val) return false;
                else return isValid(root->right, root->val); //right subtree: min_val = root->val(current node's val)
            }
            else {
                return true;
            }
        }

        if (root->left->val < root->val && root->left->val > min_val && root->val < root->right->val) {
            return isValid(root->left, min_val) && isValid(root->right, root->val);
        }

        return false;
    }
};
