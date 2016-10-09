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
    * @param T1, T2: The roots of binary tree.
    * @return: True if T2 is a subtree of T1, or false.
    */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (T2 == nullptr) return true;
        if (T1 == nullptr) return false;

        return identical(T1, T2) || isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }

    bool identical(TreeNode *T1, TreeNode *T2) {
        if (T1 == nullptr && T2 == nullptr) return true;
        if (T1 == nullptr || T2 == nullptr) return false;
        if (T1->val != T2->val) return false;

        return identical(T1->left, T2->left) && identical(T1->right, T2->right);
    }
};
