#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

//http://hihocoder.com/contest/hiho113/problem/1

void dfs(vector<int> &dt, int n, vector<int> rs, int &totalCount) {
    if (n == dt.size() && !rs.empty()) {
        totalCount++;
        return;
    }

    if (n < dt.size()) {
        int m = rs.size();

        dfs(dt, n + 1, rs, totalCount);

        if (m > 1) {
            if (dt[n] == rs[m - 2] + rs[m - 1]) {
                rs.push_back(dt[n]);
                dfs(dt, n + 1, rs, totalCount);
                rs.pop_back();
            }
        }
        else {
            if (dt[n] == 1) {
                rs.push_back(dt[n]);
                dfs(dt, n + 1, rs, totalCount);
                rs.pop_back();
            }
        }
    }
}

/*
int main() {
    vector<int> rs;
    vector<int> dt;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int tem;
        scanf("%d", &tem);
        dt.push_back(tem);
    }

    int totalCount = 0;
    dfs(dt, 0, rs, totalCount);
    printf("%d\n", totalCount);

    system("pause");
    return 0;
}
*/