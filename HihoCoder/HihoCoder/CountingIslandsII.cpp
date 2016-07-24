#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, int> pos;

map<pos, bool> data;
map<pos, bool> tem;
int ii[2] = { -1, 1 };
int jj[2] = { -1, 1 };

void depthSearch(pos p) {
	tem[p] = false;

	for (int k = 0; k < 2; k++) {
		int iii = p.first + ii[k];
		pos new_p = make_pair(iii, p.second);
		if (tem.find(new_p) != tem.end() && tem[new_p]) depthSearch(new_p);
	}

	for (int k = 0; k < 2; k++) {
		int jjj = p.second + jj[k];
		pos new_p = make_pair(p.first, jjj);
		if (tem.find(new_p) != tem.end() && tem[new_p]) depthSearch(new_p);
	}
}

/*
int main() {
	int n;
	scanf("%d", &n);

	while (n--) {
		int islandCount = 0;
		int i, j;
		scanf("%d %d", &i, &j);
		pos p = make_pair(i, j);
		//data.insert(pair<pos, bool>(p, true));
		data[p] = true;
		tem = data;

		for (map<pos, bool>::iterator it = tem.begin(); it != tem.end(); it++) {
			if (it->second) {
				depthSearch(it->first);
				islandCount++;
			}
		}
		printf("%d\n", islandCount);
	}

	system("pause");
	return 0;
}*/

	

/*
char data[1000][1000];
char tem[1000][1000];
int ii[2] = { -1, 1 };
int jj[2] = { -1, 1 };

void depthSearch(int i, int j) {
tem[i][j] = '.';

for (int k = 0; k < 2; k++) {
int iii = i + ii[k];
if (0 <= iii && iii < 1000 && tem[iii][j] == '#') depthSearch(iii, j);
}

for (int k = 0; k < 2; k++) {
int jjj = j + jj[k];
if (0 <= jjj && jjj < 1000 && tem[i][jjj] == '#') depthSearch(i, jjj);
}
}

int main() {
memset(data, '.', sizeof(data));
memset(tem, '.', sizeof(tem));
int max_i = 0;
int max_j = 0;
int n;
scanf("%d", &n);

while (n--) {
int islandCount = 0;
int i, j;
scanf("%d %d", &i, &j);
max_i = max(max_i, i);
max_j = max(max_j, j);
data[i][j] = '#';
memcpy(tem, data, sizeof(data));

for (int i = 0; i <= max_i; i++) {
for (int j = 0; j <= max_j; j++) {
if (tem[i][j] == '#') {
depthSearch(i, j);
islandCount++;
}
}
}

printf("%d\n", islandCount);
}

system("pause");
return 0;
}
*/