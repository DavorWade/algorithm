#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 1010;
int pre[MAX * MAX];
int grip[MAX][MAX];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void clear() {
    memset(pre, -1, sizeof(pre));
    memset(grip, 0, sizeof(grip));
}

int findPre(int x) {
    if (pre[x] == -1) {
        return pre[x] = x;
    }

    return pre[x] == x ? pre[x] : findPre(pre[x]);
}

void unionSet(int x, int y) {
    int fx = findPre(x);
    int fy = findPre(y);

    if (fx != fy) {
        pre[fx] = fy;
    }
}

/*
int main() {
    clear();
    int cnt = 0;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        cnt++;
        grip[x][y] = 1;

        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (0 <= nx && nx < 1000 && 0 <= ny && ny < 1000) {
                if (grip[nx][ny] == 1 && findPre(nx * 1000 + ny) != findPre(x * 1000 + y)) {
                    cnt--;
                    unionSet(nx * 1000 + ny, x * 1000 + y);
                }
            }
        }

        printf("%d\n", cnt);
    }

    //system("pause");
    return 0;
}
*/