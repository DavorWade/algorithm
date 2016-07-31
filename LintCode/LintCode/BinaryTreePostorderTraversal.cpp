#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
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
    * @return: Postorder in vector which contains node values.
    */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> rs;
        stack<TreeNode *> s;
        TreeNode *p, *q;
        p = root;

        do {
            while (p != nullptr) {
                s.push(p);
                p = p->left;
            }
            q = nullptr;
            while (!s.empty()) {
                p = s.top();
                s.pop();

                if (p->right == q) {
                    rs.push_back(p->val);
                    q = p;
                }
                else {
                    s.push(p);
                    p = p->right;
                    break;
                }
            }
        } while (!s.empty());

        return rs;
    }
};