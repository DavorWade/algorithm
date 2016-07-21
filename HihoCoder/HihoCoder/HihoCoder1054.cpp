#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>


using namespace std;

int rs; // total legal solution
int totalEdgeCount; //total edge count in every input data
int record[10][10]; //store illegal edge
int data[10][10]; //store edge from input data 
int pointCount; //total point count in result
int vis[10]; // is visited

void init() {
	record[1][3] = record[3][1] = record[1][7] = record[7][1] = 1;
	record[1][9] = record[9][1] = record[3][7] = record[7][3] = 1;
	record[9][3] = record[3][9] = record[9][7] = record[7][9] = 1;
	record[2][8] = record[8][2] = record[4][6] = record[6][4] = 1;
}

void depSearch(int leftPoint, int currPointCount, int currEdgeCount) {
	if (currPointCount == pointCount && currEdgeCount == totalEdgeCount) {
		rs++;
		return;
	}

	for (int i = 1; i < 10; i++) {
		if (!vis[i]) {
			if (record[leftPoint][i] && !vis[(leftPoint + i) / 2]) continue;
			vis[i] = 1;
			if (data[leftPoint][i]) 
				depSearch(i, currPointCount + 1, currEdgeCount + 1);
			else 
				depSearch(i, currPointCount + 1, currEdgeCount);
			vis[i] = 0;
		}
	}
}

int main() {
	int n, m, a, b;
	scanf("%d", &n);

	init();
	while (n > 0) {
		scanf("%d", &m);

		memset(vis, 0, sizeof(vis));
		memset(data, 0, sizeof(data));

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			data[a][b] = data[b][a] = 1;
		}

		rs = 0;
		totalEdgeCount = m;
		for (pointCount = max(4, m + 1); pointCount < 10; pointCount++) {
			for (int i = 1; i < 10; i++) {
				vis[i] = 1;
				depSearch(i, 1, 0);
				vis[i] = 0;
			}
		}

		printf("%d\n", rs);
		n--;
	}

	return 0;
}
