#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
    * @param root: The root of binary tree.
    * @return: The maximum amount of money you can rob tonight
    */
    int houseRobber3(TreeNode* root) {
        // write your code here
        unordered_map<TreeNode*, int> m;

        return dfs(root, m);
    }

    int dfs(TreeNode *root, unordered_map<TreeNode*, int> &m) {
        if (root == nullptr) return 0;
        if (m.count(root)) return m[root];

        int val = 0;
        if (root->left) {
            val += dfs(root->left->left, m) + dfs(root->left->right, m);
        }
        if (root->right) {
            val += dfs(root->right->left, m) + dfs(root->right->right, m);
        }
        val = max(val + root->val, dfs(root->left, m) + dfs(root->right, m));
        m[root] = val;

        return val;
    }
};
