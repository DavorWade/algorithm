#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>

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
public:
	/**
	* @param S, T: Two string.
	* @return: Count the number of distinct subsequences
	*/
	int numDistinct(string &S, string &T) {
		// write your code here
		if (S.size() < T.size()) return 0;
		vector<vector<int> > dp(T.size() + 1, vector<int>(S.size() + 1, 0));
		for (int i = 0; i < S.size(); i++) {
			dp[0][i] = 1;
		}

		for (int i = 1; i < S.size(); i++) {
			for (int j = 1; j < T.size(); j++) {
				if (T[j] == S[i])
					dp[j][i] = dp[j][i - 1] + dp[j - 1][i-1];
				else
					dp[j][i] = dp[j][i - 1];
			}
		}

		return dp[T.size()][S.size()];
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


