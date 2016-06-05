#include <stdio.h>
#include <stdlib.h>
#include <stack>
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

int minimumTotal(vector<vector<int> > &triangle) {
	vector<int> dp;
	int rows = triangle.size();
	for (int i = 0; i < rows; i++) {
		dp.push_back(triangle[rows - 1][i]);
	}

	for (int row = rows - 2; row >= 0; row--) {
		for (int j = 0; j <= row; j++) {
			dp[j] = triangle[row][j] + min(dp[j], dp[j + 1]);
		}
	}

	return dp[0];
}

/*
int main(int argc, char *argv[]) {

	printf("\n");

	system("pause");
	return 0;
}
*/