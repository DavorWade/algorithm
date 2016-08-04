#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int n;
/*
void trav(vector<vector<int> > &t, int k, vector<vector<int> > &rs, vector<int> &path) {
    vector<int> root = t[k];

    if (!root.empty()) {
        sort(root.begin(), root.end());

        do {
            for (int i = 0; i < root.size(); i++) {
                path.push_back(root[i]);
                trav(t, root[i], rs, path);
            }
            if (k == 1) {
                rs.push_back(path);
                path.clear();
                path.push_back(1);
            }
        } while (next_permutation(root.begin(), root.end()));
    }
}
*/

void trav(vector<vector<int> > &t, int k, int count, vector<vector<int> > &rs, vector<int> path) {
    vector<int> root = t[k];
    if (count == n) {
        rs.push_back(path);
        return;
    }

    if (!root.empty()) {
        vector<int> pathTem = path;
        sort(root.begin(), root.end());

        do {
            for (int i = 0; i < root.size(); i++) {
                pathTem.push_back(root[i]);
                trav(t, root[i], count + 1, rs, pathTem);
            }
            pathTem = path;
        } while (next_permutation(root.begin(), root.end()));
    }
}

int main() {
    vector<int> p;
    vector<int> q;
    
    scanf("%d", &n);
    vector<vector<int> > t(n + 1, vector<int>());
    vector<vector<int> > rs;
    int min_money = INT_MAX;

    for (int i = 0; i < n; i++) {
        int pp, qq;
        scanf("%d %d", &pp, &qq);
        p.push_back(pp);
        q.push_back(qq);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        t[a].push_back(b);
    }

    vector<int> path;
    path.push_back(1);
    trav(t, 1, 1, rs, path);

    for (int j = 0; j < rs.size(); j++) {
        int tem = 0;
        for (int k = 0; k < rs[j].size(); k++) {
            tem = tem + p[rs[j][k] - 1] - q[rs[j][k] - 1];
        }
        int last = rs[j][rs[j].size() - 1] - 1;
        min_money = min(min_money, tem + q[last]);
    }

    /*printf("---------------\n");
    for (int j = 0; j < t.size(); j++) {
        if (!t[j].empty()) {
            printf("%d:", j);
            for (int k = 0; k < t[j].size(); k++) {
                printf("%d ", t[j][k]);
            }
            printf("\n");
        }
    }
    printf("---------------\n\n");
    */

    for (int j = 0; j < rs.size(); j++) {
        for (int k = 0; k < rs[j].size(); k++) {
            printf("%d ", rs[j][k]);
        }
        printf("\n");
    }

    printf("%d\n", min_money);

    system("pause");
    return 0;
}