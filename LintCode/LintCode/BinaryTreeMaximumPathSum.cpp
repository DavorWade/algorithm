#include <stdio.h>
#include <stdlib.h>
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
	* @param root: The root of binary tree.
	* @return: An integer
	*/
	int maxPathSum(TreeNode *root) {
		// write your code here
		if (NULL == root) return 0;

		return helper(root).second;
	}
private:
	pair<int, int> helper(TreeNode *root) {
		if (NULL == root) {
			return make_pair(0, INT_MIN);
		}

		pair<int, int> leftTree = helper(root->left);
		pair<int, int> rightTree = helper(root->right);

		int single_path_sum = max(leftTree.first, rightTree.first) + root->val;
		single_path_sum = max(0, single_path_sum);

		int max_sub_sum = max(leftTree.second, rightTree.second);
		int max_path_sum = root->val + leftTree.first + rightTree.first;
		max_path_sum = max(max_sub_sum, max_path_sum);

		return make_pair(single_path_sum, max_path_sum);
	}
};