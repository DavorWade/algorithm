#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

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

int visit(const binary_tree_node_t* node) {
    return node->elem;
}

void preorder(const binary_tree_node_t* root, int(*visit)(const binary_tree_node_t*)) {
    const binary_tree_node_t* p = root;
    stack<const binary_tree_node_t*> s;

    if (p != nullptr) s.push(p);

    while (!s.empty()) {
        p = s.top();
        s.pop();

        int val = visit(p);
        printf("%d ", val);

        if (p->right != nullptr) s.push(p->right);
        if (p->left != nullptr) s.push(p->left);
    }
}

void inorder(const binary_tree_node_t* root, int(*visit)(const binary_tree_node_t*)) {
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
            int ele = visit(p);
            printf("%d ", ele);

            p = p->right;
        }
    }
}

void postorder(const binary_tree_node_t* root, int(*visit)(const binary_tree_node_t*)) {
    const binary_tree_node_t* p = root;
    const binary_tree_node_t* q = nullptr;
    stack<const binary_tree_node_t*> s;

    while (!s.empty() || p != nullptr) {

        if (p != nullptr && p->left != q) {
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top();
            s.pop();
            if (p->right != nullptr) {
                s.push(p);
                p = p->right;
            }
            else {
                int ele = visit(p);
                q = p;
                p = nullptr;
                printf("%d ", ele);
            }
        }
    }
}

void post_order(const binary_tree_node_t *root, int(*visit)(const binary_tree_node_t*)) {
    /* p，正在访问的结点，q，刚刚访问过的结点*/
    const binary_tree_node_t *p, *q;
    stack<const binary_tree_node_t *> s;
    p = root;

    do {
        while (p != nullptr) { /* 往左下走*/
            s.push(p);
            p = p->left;
        }q
            = nullptr;
        while (!s.empty()) {
            p = s.top();
            s.pop();
            /* 右孩子不存在或已被访问，访问之*/
            if (p->right == q) {
                visit(p);
                q = p; /* 保存刚访问过的结点*/
            }
            else {
                /* 当前结点不能访问，需第二次进栈*/
                s.push(p);
                /* 先处理右子树*/
                p = p->right;
                break;
            }
        }
    } while (!s.empty());
}


void level_order(const binary_tree_node_t *root, int(*visit)(const binary_tree_node_t*)) {
    const binary_tree_node_t* p = root;
    queue<const binary_tree_node_t*> q;

    if (p != nullptr) q.push(p);

    while (!q.empty()) {
        p = q.front();
        q.pop();
        int val = visit(p);
        printf("%d ", val);

        if (p->left != nullptr) q.push(p->left);
        if (p->right != nullptr) q.push(p->right);
    }
}

/*
int main(int argc, char *argv[]) {
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

    level_order(&root, *visit);
    printf("\n");

    preorder(&root, *visit);
    printf("\n");

    inorder(&root, *visit);
    printf("\n");

    system("pause");
    return 0;
}
*/