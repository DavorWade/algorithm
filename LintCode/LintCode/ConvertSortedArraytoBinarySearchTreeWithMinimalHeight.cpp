#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>

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

/**
* Definition of TreeNode:
* class TreeNode {
* public:
*     int val;
*     TreeNode *left, *right;
*     TreeNode(int val) {
*         this->val = val;
*         this->left = this->right = NULL;
*     }
* }
*/
class Solution {
public:
    /**
    * @param A: A sorted (increasing order) array
    * @return: A tree node
    */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if (A.size() < 1) return nullptr;
        int s = 0;
        int end = A.size();
        int mid = s + (end - s) / 2;

        TreeNode *root = dfs(A, s, end);

        return root;
    }

    TreeNode *dfs(vector<int> &A, int s, int end) {
        int mid = s + (end - s) / 2;
        TreeNode *root = new TreeNode(A[mid]);

        if (mid > s) root->left = dfs(A, s, mid);
        if (end - mid > 1) root->right = dfs(A, mid + 1, end);

        return root;
    }
};

