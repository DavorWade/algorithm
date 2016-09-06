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


class Solution {
    /**
    * @param root: The root of binary tree.
    * @return: A list of lists of integer include
    *          the zigzag level order traversal of its nodes' values
    */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> >  rs;
        if (root == nullptr) return rs;

        int level = 1;
        int curr_num = 0;
        int total_num = 1;
        int node_num = total_num - curr_num;

        vector<int> tem;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            if (node_num != 0) {
                node_num--;
                curr_num++;
                TreeNode *node = q.front();
                q.pop();

                if (level % 2 == 1) {
                    tem.push_back(node->val);
                }
                else {
                    vector<int>::iterator it = tem.begin();
                    tem.insert(it, node->val);
                }


                if (node->left != nullptr) {
                    q.push(node->left);
                    total_num++;
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    total_num++;
                }
            }
            else {
                rs.push_back(tem);
                tem.clear();

                level++;
                node_num = total_num - curr_num;
            }
        }

        if (tem.size() > 0) {
            rs.push_back(tem);
        }

        return rs;
    }
};