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
    /* Ԥ�ȷ����һ�е�1 */
    q.push(1);
    for (int i = 0; i <= n; i++) { /* ���д���*/
        int s = 0;
        q.push(s); /* �ڸ��м����һ��0*/
        /* �����i �е�i+2 ��ϵ��������һ��0��*/
        for (int j = 0; j < i + 2; j++) {
            int t;
            int tmp;
            t = q.front(); /* ��ȡһ��ϵ��������t*/
            q.pop();
            tmp = s + t; /* ������һ��ϵ������������*/
            q.push(tmp);
            s = t; /* ��ӡһ��ϵ������i+2 ����0*/
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
