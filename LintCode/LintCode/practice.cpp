#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>

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


