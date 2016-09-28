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

//DP
class Solution1 {
public:
    /**
    * @param root: The root of binary tree.
    * @return: The maximum amount of money you can rob tonight
    * @date: 2016-9-28
    */
    int houseRobber3(TreeNode* root) {
        // write your code here
        vector<int> ans = dp(root);
        return max(ans[0], ans[1]);
    }

    vector<int> dp(TreeNode* root) {
        if (root == nullptr) {
            vector<int> now{0, 0};
            return now;
        }

        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);
        vector<int> now(2, 0);
        now[0] = max(left[0], left[1]) + max(right[0], right[1]);
        now[1] = left[0] + right[0] + root->val;
        return now;
    }
};