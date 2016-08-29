#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <locale>

using namespace std;

/*
 * @DATE: 2016-8-27
 * http://hihocoder.com/contest/hiho112/problem/1
 */

vector<map<pair<int, int>, int> > dt;

class Solution {
public:
    vector<string> &split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        split(s, delim, elems);
        return elems;
    }

    void queryOp(int i, long long &tthd, int chd) {
        if (i <= dt.size()) {
            for (map<pair<int, int>, int>::iterator it = dt[i - 1].begin(); it != dt[i - 1].end(); it++) {
                int vv = it->first.second;
                int kk = it->second;

                //printf("%d %d\n", vv, kk);
                //printf("%d\n", chd + kk);
                tthd = tthd + chd + kk;
                //printf("%d\n", tthd);
                queryOp(vv, tthd, chd + kk);
            }
        }
    }

    void editOp(int i, int j, int k) {
        pair<int, int> ij = make_pair(i, j);
        dt[i - 1][ij] = k;
    }
};

/*
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
    }

    getchar();
    for (int j = 0; j < m; j++) {
        string op;
        getline(cin, op);

        if ("QUERY" == op) {
            long long thd = 0;
            for (int i = 1; i <= dt.size(); i++) {
                long long onePointThd = 0;
                s.queryOp(i, onePointThd, 0);
                thd += onePointThd;
            }
            printf("%lld\n", thd);
        }
        else {
            vector<string> rs;
            char delim = ' ';
            rs = s.split(op, delim);

            int i = stoi(rs[1]);
            int j = stoi(rs[2]);
            int kk = stoi(rs[3]);

            s.editOp(i, j, kk);
        }
    }
    
    system("pause");
    return 0;
}
*/