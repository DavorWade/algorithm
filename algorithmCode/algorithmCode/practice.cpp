#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

/** 结点的数据*/
typedef int tree_node_elem_t;
/*
*@struct
*@brief 二叉树结点
*/
struct binary_tree_node_t {
	binary_tree_node_t* left;
	binary_tree_node_t* right;
	tree_node_elem_t elem;
};

void inorder(const binary_tree_node_t* root, int(*visit)(const binary_tree_node_t*)) {
	const binary_tree_node_t* p = root;
	stack<const binary_tree_node_t*> s;

	/*if (p != nullptr) s.push(p);

	while (!s.empty()) {
		p = s.top();
		s.pop();

		if (p->left != nullptr) {
			s.push(p);
			s.push(p->left);
		}
		else {
			visit(p);
			if (p->right != nullptr)
				s.push(p->right);
		}
	}*/
	while (!s.empty() || p != nullptr) {
		if (p != nullptr) {
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			s.pop();
			visit(p);

			p = p->right;
		}
	}
}

int main(int argc, char *argv[])
{
	//printf("%d\n", (1 << n) - 1); /* 总次数*/

	return 0;
}

