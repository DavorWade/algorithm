#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

/** ��������*/
typedef int tree_node_elem_t;
/*
*@struct
*@brief ���������
*/
struct binary_tree_node_t {
	binary_tree_node_t* left;
	binary_tree_node_t* right;
	tree_node_elem_t elem;
};

void preorder(const binary_tree_node_t* root, int(*visit)(const binary_tree_node_t*)) {
	const binary_tree_node_t* tem = root;
	stack<const binary_tree_node_t*> s;

	if (tem != nullptr) s.push(tem);

	while (!s.empty()) {
		tem = s.top();
		s.pop();
		visit(tem);

		if (tem->right != nullptr) s.push(tem->right);
		if (tem->left != nullptr) s.push(tem->left);
	}
}

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
	//printf("%d\n", (1 << n) - 1); /* �ܴ���*/

	return 0;
}

