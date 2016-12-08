#include <stdio.h>
#include <stdlib.h>
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
    * @aaram a, b, the root of binary trees.
    * @return true if they are identical, or false.
    * @date: 2016-12-4
    */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        bool rs = true;
        if (a == nullptr && b == nullptr) return true;
        else if (a == nullptr || b == nullptr) return false;

        if (a->val != b->val) return false;
        // rs = isIdentical(a->left, b->left);
        // if (!rs) return false;
        // rs = isIdentical(a->right, b->right);

        return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
    }
};
