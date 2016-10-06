#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param A: an integer array.
    * @param k: a positive integer (k <= length(A))
    * @param target: a integer
    * @return a list of lists of integer
    */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int> > rs;

        vector<vector<int> > combination = getCombination(A.size(), k);
        for (int i = 0; i < combination.size(); i++) {
            vector<int> tem;
            int sum = 0;
            for (int j = 0; j < combination[i].size(); j++) {
                tem.push_back(A[combination[i][j]]);
                sum += A[combination[i][j]];
            }
            if (sum == target) rs.push_back(tem);
        }

        return rs;
    }

    vector<vector<int> > getCombination(int n, int r) {
        vector<vector<int> > combination;
        vector<bool> v(n);
        fill(v.begin(), v.begin() + r, true);

        do {
            vector<int> tem;
            for (int i = 0; i < n; i++) {
                if (v[i]) tem.push_back(i);
            }

            if (!tem.empty()) combination.push_back(tem);
        } while (prev_permutation(v.begin(), v.end()));

        return combination;
    }
};

//DFS
class Solution {
public:
    /**
    * @param A: an integer array.
    * @param k: a positive integer (k <= length(A))
    * @param target: a integer
    * @return a list of lists of integer
    */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int> > rs;
        vector<int> tem;
        dfs(A, tem, rs, 0, A.size(), 0, k, target, 0);

        return rs;
    }

    void dfs(vector<int> &A, vector<int> &tem, vector<vector<int> > &rs, int nn, int n, int kk, int k, int &target, int sum) {
        if (k == kk && sum == target) {
            rs.push_back(tem);
            return;
        }
        if (nn == n) return;

        dfs(A, tem, rs, nn + 1, n, kk, k, target, sum);

        tem.push_back(A[nn]);
        dfs(A, tem, rs, nn + 1, n, kk + 1, k, target, sum + A[nn]);
        tem.pop_back();
    }
};

