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
private:
	class PathSumType {
	public:
		int singlePathMax;
		int combinedPathMax;
		PathSumType(int singlePathMax, int combinedPathMax) {
			this->singlePathMax = singlePathMax;
			this->combinedPathMax = combinedPathMax;
		}
	};

	PathSumType helper(TreeNode *root) {
		if (root == nullptr) return PathSumType(0, INT_MIN);
		PathSumType left = helper(root->left);
		PathSumType right = helper(root->right);

		int singlePathMax = max(left.singlePathMax, right.singlePathMax) + root->val;
		singlePathMax = max(0, singlePathMax);

		int combinedPathMax = max(left.combinedPathMax, right.combinedPathMax);
		combinedPathMax = max(combinedPathMax, left.singlePathMax + right.singlePathMax + root->val);

		return PathSumType(singlePathMax, combinedPathMax);
	}

public:
	/**
	* @param root: The root of binary tree.
	* @return: An integer
	*/
	int maxPathSum(TreeNode *root) {
		// write your code her
		return helper(root).combinedPathMax;
	}
};

/*
int main(int argv, char *argc[]) {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	
	Solution s;
	int m = s.maxPathSum(root);
	printf("%d", m);

	printf("\n");
	system("pause");
	return 0;
}
*/