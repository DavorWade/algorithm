#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, m;
char data[100][100];

void findPonds(int x, int y) {
	data[x][y] = '.';

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			int xx = x + i;
			int yy = y + j;
			if (0 <= xx && xx <= n && 0 <= yy && yy <= m && data[xx][yy] == 'W') findPonds(xx, yy);
		}
	}
}

int main(int argc, char *argv[]) {
	int count = 0;
	char tem;
	scanf("%d %d", &n, &m);
	getchar();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &tem);
			data[i][j] = tem;
		}
		getchar();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (data[i][j] == 'W') {
				findPonds(i, j);
				count++;
			}
		}
	}

	printf("%d\n", count);

	system("pause");
	return 0;
}