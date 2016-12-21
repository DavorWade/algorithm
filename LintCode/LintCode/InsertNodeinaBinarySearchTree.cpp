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
    * @param root: The root of the binary search tree.
    * @param node: insert this node into the binary search tree
    * @return: The root of the new binary search tree.
    */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if (root == nullptr) {
            root = node;
            return root;
        }

        TreeNode* curr = root;
        while (true) {
            if (node->val < curr->val) {
                if (curr->left != nullptr) {
                    curr = curr->left;
                }
                else {
                    break;
                }
            }
            else {
                if (curr->right != nullptr) {
                    curr = curr->right;
                }
                else {
                    break;
                }
            }
        }

        if (node->val < curr->val) {
            curr->left = node;
        }
        else {
            curr->right = node;
        }

        return root;
    }
};
