#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param n an integer
    * @param edges a list of undirected edges
    * @return true if it's a valid tree, or false
    * @date: 2016-9-13
    */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if (n - 1 != edges.size()) return false;

        int rootCount = 0;
        vector<int> t(n, 0);
        vector<int> pre(n, 0);
        for (int i = 1; i < n; i++) pre[i] = i;

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] == edges[i][1]) return false;

            unionOp(pre, edges[i][0], edges[i][1]);
        }

        for (int i = 0; i < n; i++) {
            t[findOp(pre, i)] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (t[i]) rootCount++;
        }
        if (rootCount > 1) return false;

        return true;
    }

    int findOp(vector<int> &pre, int x) {
        int r = x;
        while (r != pre[r]) r = pre[r];

        int i = x, j;
        while (pre[i] != r) {
            j = pre[i];
            pre[i] = r;
            i = j;
        }
        return r;
    }

    void unionOp(vector<int> &pre, int x, int y) {
        int fx = findOp(pre, x), fy = findOp(pre, y);

        if (fx != fy) {
            pre[fy] = fx;
        }
    }
};
