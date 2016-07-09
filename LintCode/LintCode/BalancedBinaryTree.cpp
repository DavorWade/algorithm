#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

/**
* Definition of TreeNode:
*/
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
	* @return: True if this Binary tree is Balanced, or false.
	* @date: 2016.6.9
	*/
	bool isBalanced(TreeNode *root) {
		return depth(root) != -1;
	}

	int depth(TreeNode *root) {
		if (root == NULL) {
			return 0;
		}
		int left = depth(root->left);
		if (left == -1 ) return -1;

		int right = depth(root->right);
		if (right == -1) return -1;

		if (abs(left - right) > 1) return -1;

		return max(left, right) + 1;
	}
};