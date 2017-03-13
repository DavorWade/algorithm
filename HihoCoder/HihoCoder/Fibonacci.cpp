#include <stdlib.h>
#include <stdio.h>
#include<algorithm>
#include <vector>

using namespace std;

//http://hihocoder.com/contest/hiho113/problem/1

long long dp[100], m, n, a[1000009], f[100], ans = 0;

/*
int main() {
    f[1] = 1;
    f[2] = 1;
    m = 2;

    while (f[m] < 100000) {
        f[m + 1] = f[m] + f[m - 1];
        m++;
    }

    scanf("%lld", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    for (int i = 0; i < n; i++) {
        int it = lower_bound(f + 1, f + m + 1, a[i]) - f;
        if (it >= 3 && it <= m && f[it] == a[i]) {
            dp[it] += dp[it - 1];
            ans += dp[it - 1];

            dp[it] %= 1000000007;
            ans %= 1000000007;
        }
        else if (1 == a[i]) {
            dp[2] += dp[1];
            dp[1]++;
            ans += dp[1];
        }
    }
    printf("%lld\n", ans);

    return 0;
}
*/

/*
// DFS, Time Limited Error.
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
