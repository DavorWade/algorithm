#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

/*
 * @DATE: 2016-8-27
 * http://hihocoder.com/contest/hiho112/problem/1
 */

vector<map<pair<int, int>, int> > dt;

class Solution {
public:
    void queryOp(int i, int first, long long &tthd, int chd) {
        if (i <= dt.size()) {
            for (map<pair<int, int>, int>::iterator it = dt[i - 1].begin(); it != dt[i - 1].end(); it++) {
                int vv = it->first.second;
                int kk = it->second;

                if (vv != first) {
                    //printf("vv, kk: %d %d\n", vv, kk);
                    //printf("chd + kk: %d\n", chd + kk);
                    tthd = tthd + chd + kk;
                    //printf("tthd: %d\n", tthd);
                    queryOp(vv, i, tthd, chd + kk);
                }
            }
        }
    }

    void editOp(int i, int j, int k) {
        pair<int, int> ij = make_pair(i, j);
        dt[i - 1][ij] = k;

        pair<int, int> ji = make_pair(j, i);
        dt[j - 1][ji] = k;
    }
};

/**/
int main() {
    Solution s;
    int n, m;
    scanf("%d %d", &n, &m);
    dt = vector<map<pair<int, int>, int> >(n, map<pair<int, int>, int>());

    for (int i = 0; i < n - 1; i++) {
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);

        pair<int, int> uv = make_pair(u, v);
        dt[u - 1][uv] = k;

        pair<int, int> vu = make_pair(v, u);
        dt[v - 1][vu] = k;
    }

    /*for (int t = 0; t < dt.size(); t++) {
        map<pair<int, int>, int> tem = dt[t];
        map<pair<int, int>, int>::iterator it = tem.begin();

        for (;it != tem.end(); it++) {
            printf("%d %d: %d\n", it->first.first, it->first.second, it->second);
        }
        printf("\n");
    }*/

    for (int j = 0; j < m; j++) {
        char op[15];
        scanf("%s", op);

        if ('Q' == op[0]) {
            long long thd = 0;
            for (int i = 1; i <= dt.size(); i++) {
                long long onePointThd = 0;
                s.queryOp(i, i, onePointThd, 0);
                thd += onePointThd;
            }
            printf("%lld\n", thd / 2);
        }
        else {
            int i, j, kk;
            scanf("%d %d %d", &i, &j, &kk);

            s.editOp(i, j, kk);
        }
    }
    
    system("pause");
    return 0;
}
