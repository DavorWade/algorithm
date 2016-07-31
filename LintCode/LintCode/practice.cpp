#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <sstream>
#include <locale>

using namespace std;

void yanghui_triangle(const int n) {
    queue<int> q;
    /* 预先放入第一行的1 */
    q.push(1);
    for (int i = 0; i <= n; i++) { /* 逐行处理*/
        int s = 0;
        q.push(s); /* 在各行间插入一个0*/
        /* 处理第i 行的i+2 个系数（包括一个0）*/
        for (int j = 0; j < i + 2; j++) {
            int t;
            int tmp;
            t = q.front(); /* 读取一个系数，放入t*/
            q.pop();
            tmp = s + t; /* 计算下一行系数，并进队列*/
            q.push(tmp);
            s = t; /* 打印一个系数，第i+2 个是0*/
            if (j != i + 1) {
                printf("%d ", s);
            }
        }
        printf("\n");
    }
}

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
            while (!s.empty()){
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

/*
int main(int argc, char *argv[]) {
    int rs = aplusb(2, 4);
    printf("%d", rs);

    printf("\n");
    system("pause");
    return 0;
}
*/
