#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Country H is going to carry out a huge artificial islands project. The project region is divided into a 1000x1000 grid. The whole project will last for N weeks. Each week one unit area of sea will be filled with land.

As a result, new islands (an island consists of all connected land in 4 -- up, down, left and right -- directions) emerges in this region. Suppose the coordinates of the filled units are (0, 0), (1, 1), (1, 0). Then after the first week there is one island:
*/
using namespace std;

int pre[1001];
int t[1001];
int isFilled[10001][1001];
int ii[2] = { -1, 1 };
int jj[2] = { -1, 1 };
bool isUnioned = false;

int find_root(int x) {
    int r = x;
    if (pre[r] == -1) return -1;
    while (pre[r] != r) r = pre[r];

    int i, j;
    i = x;
    while (pre[i] != r) {
        j = pre[i];
        pre[i] = r;
        i = j;
    }

    return r;
}

void union_op(int x, int y) {
    int fx = find_root(x);
    int fy = find_root(y);
    if (fx < 0) {
        pre[x] = x;
        fx = x;
    }
    if (fy < 0) {
        pre[y] = y;
        fy = y;
    }

    if (fx != fy) pre[fx] = fy;
}

/*
int main() {
    int n;
    scanf("%d", &n);

    memset(isFilled, 0, sizeof(isFilled));
    for (int i = 0; i < 1001; i++) pre[i] = -1;

    while (n--) {
        int islandCount = 0;
        memset(t, 0, sizeof(t));
        int x, y;
        scanf("%d %d", &x, &y);
        isFilled[x][y] = 1;

        for (int i = 0; i < 2; i++) {
            int xx = x + ii[i];
            if (0 <= xx && xx < 1000 && isFilled[xx][y] == 1) {
                union_op(x, y);
                union_op(xx, y);
                isUnioned = true;
            }
        }
        if (!isUnioned) {
            for (int j = 0; j < 2; j++) {
                int yy = y + jj[j];
                if (0 <= yy && yy < 1000 && isFilled[x][yy] == 1) {
                    union_op(x, y);
                    union_op(x, yy);
                    isUnioned = true;
                }
            }
        }

        if (!isUnioned) {
            printf("no union:%d, %d\n", x, y);
            int xr = find_root(x);
            int yr = find_root(y);

            if (xr == -1 && yr == -1) {
                pre[x] = x;
                pre[y] = x;
            }
            else if (xr != -1 && yr != -1) {

            }
            else if (xr != -1) {
                pre[y] = y;
            }
            else {
                pre[x] = x;
            }
        }

        for (int i = 0; i < 1001; i++) {
            int tem = find_root(i);
            if (tem > -1)
                t[tem] = 1;
        }
        for (int i = 0; i < 1001; i++){
            if (t[i]) islandCount++;
        }

        printf("%d\n", islandCount);
    }

    system("pause");
    return 0;
}*/

/*
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