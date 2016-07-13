#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

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
	* @param root the root of the binary tree
	* @return all root-to-leaf paths
	*/
	vector<string> binaryTreePaths(TreeNode* root) {
		// Write your code here
		vector<string> rs;
		string s = "";
		if (root != nullptr) {
			findTreePaths(rs, root, s);
		}
		return rs;
	}

	void findTreePaths(vector<string> &rs, TreeNode* root, string s) {
		s += to_string(root->val);

		if (root->left != nullptr) {
			findTreePaths(rs, root->left, s + "->");
		}

		if (root->right != nullptr) {
			findTreePaths(rs, root->right, s + "->");
		}

		if (root->left == nullptr && root->right == nullptr) rs.push_back(s);
	}
};

/*
int main(int argc, char *argv[]) {
	TreeNode *root = new TreeNode(1);
	TreeNode *a = new TreeNode(2);
	TreeNode *b = new TreeNode(3);
	TreeNode *c = new TreeNode(5);
	root->left = a;
	root->right = b;
	a->right = c;

	Solution s;
	vector<string> rs = s.binaryTreePaths(root);
	for (int i = 0; i < rs.size(); i++) {
		cout << rs[i] << endl;
	}

	system("pause");
	return 0;
}
*/
