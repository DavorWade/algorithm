#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

//http://hihocoder.com/contest/hihointerview15/problems

using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int MAX = 1010;
int fa[MAX * MAX];
int grid[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void clear() {
    memset(fa, -1, sizeof fa);
    memset(grid, 0, sizeof grid);
}

int findset(int x) {
    if (fa[x] == -1) {
        return fa[x] = x;
    }
    return x == fa[x] ? x : fa[x] = findset(fa[x]);
}

void unionset(int x, int y) {
    int fx = findset(x), fy = findset(y);
    if (fx != fy) {
        fa[fx] = fy;
    }
}

/*
int main() {
    clear();
    int cnt = 0;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        grid[x][y] = 1;
        cnt++;
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 0 && ny >= 0 && nx < 1000 && ny < 1000) {
                if (grid[nx][ny] && findset(nx * 1000 + ny) != findset(x * 1000 + y)) {
                    cnt--;
                    unionset(nx * 1000 + ny, x * 1000 + y);
                }
            }
        }
        cout << cnt << endl;
    }

    system("pause");
    return 0;
}
*/