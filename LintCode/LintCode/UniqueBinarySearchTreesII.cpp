#include <stdio.h>
#include <stdlib.h>
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
public:
    /**
    * @paramn n: An integer
    * @return: A list of root
    */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return dfs(1, n);
    }

    vector<TreeNode *>  dfs(int min, int max) {
        vector<TreeNode *> rs;
        if (min > max) {
            rs.push_back(nullptr);
            return rs;
        }

        for (int i = min; i <= max; i++) {
            vector<TreeNode *> left = dfs(min, i - 1);
            vector<TreeNode *> right = dfs(i + 1, max);

            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    rs.push_back(root);
                }
            }
        }

        return rs;
    }
};
