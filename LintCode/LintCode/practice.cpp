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

int visit(const binary_tree_node_t* node)
{
	return node->elem;
}

void inorder(const binary_tree_node_t* root, int(*visit)(const binary_tree_node_t*)) {
	const binary_tree_node_t* p = root;
	stack<const binary_tree_node_t*> s;

	/*
	if (p != nullptr) s.push(p);

	
	while (!s.empty()) {
		p = s.top();
		s.pop();

		if (p->left != nullptr) {
			s.push(p);
			s.push(p->left);
		}
		else {
			int ele = visit(p);
			printf("%d ", ele);
			if (p->right != nullptr)
				s.push(p->right);
		}
	}
	*/

	while (!s.empty() || p != nullptr) {
		if (p != nullptr) {
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			s.pop();
			int ele = visit(p);
			printf("%d ", ele);

			p = p->right;
		}
	}
}

void postorder(const binary_tree_node_t* root, int(*visit)(const binary_tree_node_t*)) {
	const binary_tree_node_t* p = root;
	stack<const binary_tree_node_t*> s;

	while (!s.empty() || p != nullptr) {
		if (p != nullptr) {
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			s.pop();
			if (p->right != nullptr) {
				s.push(p);
				p->right;
			}
			else {
				int ele = visit(p);
				printf("%d ", ele);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	//printf("%d\n", (1 << n) - 1); /* 总次数*/
	binary_tree_node_t root;
	root.elem = 0;
	binary_tree_node_t a;
	a.elem = 1;
	binary_tree_node_t b;
	b.elem = 2;
	binary_tree_node_t c;
	c.elem = 3;
	binary_tree_node_t d;
	d.elem = 4;
	binary_tree_node_t e;
	e.elem = 5;
	binary_tree_node_t f;
	f.elem = 6;

	root.left = &a;
	root.right = &b;
	a.left = &c;
	a.right = &d;
	b.left = &e;
	b.right = &f;
	c.left = nullptr;
	c.right = nullptr;
	d.left = nullptr;
	d.right = nullptr;
	e.left = nullptr;
	e.right = nullptr;
	f.left = nullptr;
	f.right = nullptr;

	inorder(&root, *visit);
	printf("\n");

	system("pause");
	return 0;
}

