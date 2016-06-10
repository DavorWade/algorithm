#include <stdio.h>
#include <stdlib.h>
#include <vector>
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

/*
int main(int argc, char *argv[]) {
	int dimension = 2;
	vector<vector<int>> dp(dimension, vector<int>(dimension));
	dp[0][0] = 1;
	printf("dp[0][0]:%d", dp[0][0]);

	printf("\n");
	system("pause");
	return 0;
}
*/