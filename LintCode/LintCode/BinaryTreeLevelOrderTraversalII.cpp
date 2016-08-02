#include <stdlib.h>
#include <stdint.h>
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
    /**
    * @param root : The root of binary tree.
    * @return : buttom-up level order a list of lists of integer
    */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        if (root == nullptr) return vector<vector<int> >();

        vector<pair<TreeNode*, int> > q;
        int count = 0;
        int level = 1;
        q.push_back(make_pair(root, level));

        while (count < q.size()) {
            TreeNode *p = q[count].first;
            level = q[count].second;

            if (p->left) q.push_back(make_pair(p->left, level + 1));
            if (p->right) q.push_back(make_pair(p->right, level + 1));
            count++;
        }

        vector<vector<int> > rs(level, vector<int>());
        for (int i = 0; i < q.size(); i++) {
            rs[level - q[i].second].push_back(q[i].first->val);
        }

        return rs;
    }
};
