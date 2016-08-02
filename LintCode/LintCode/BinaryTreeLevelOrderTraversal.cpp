#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

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
    /**
    * @param root: The root of binary tree.
    * @return: Level order a list of lists of integer
    */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        if (root == nullptr) return vector<vector<int> >();
        int depth = getDepth(root);
        vector<vector<int> > rs(depth, vector<int>());

        traversal(root, 0, rs);

        return rs;
    }

    int getDepth(TreeNode *root) {
        if (root == nullptr) return 0;

        int left = getDepth(root->left);
        int right = getDepth(root->right);

        return max(left, right) + 1;
    }

    void traversal(TreeNode *root, int currDepth, vector<vector<int> > &rs) {
        if (root == nullptr) return;
        else rs[currDepth].push_back(root->val);

        traversal(root->left, currDepth + 1, rs);
        traversal(root->right, currDepth + 1, rs);
    }
};
