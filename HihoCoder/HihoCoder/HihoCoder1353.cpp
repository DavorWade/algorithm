#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

void dfs(vector<int> &data, int d, int n, int x, int &rs, int sum) {
    if (d == n) {
        if (sum >= x) {
            if (sum < rs) rs = sum;
        }
        return;
    }

    if (sum >= x) { //backtracking(ºÙ÷¶)
        dfs(data, n, n, x, rs, sum);
    }
    else {
        dfs(data, d + 1, n, x, rs, sum);

        dfs(data, d + 1, n, x, rs, sum + data[d]);
    }
}

/*
int main() {
    vector<int> data;
    int rs = INT_MAX;
    int n, x;
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++) {
        int pay;
        scanf("%d", &pay);
        data.push_back(pay);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    if (sum < x) {
        printf("-1\n");
    }
    else {
        dfs(data, 0, n, x, rs, 0);

        printf("%d\n", rs);
    }

    system("pause");
    return 0;
}
*/