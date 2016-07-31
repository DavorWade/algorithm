#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/en/problem/backpack/
    * @param m: An integer m denotes the size of a backpack
    * @param A: Given n items with size A[i]
    * @return: The maximum size
    */
    int backPack(int m, vector<int> A) {
        // write your code here
        if (A.empty() || m < 1) return 0;
        const int N = A.size() + 1;
        const int M = m + 1;
        vector<vector<bool> > dp(N, vector<bool>(M, false));

        dp[0][0] = true;
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= A[i - 1] && dp[i - 1][j - A[i - 1]]) {
                    dp[i][j] = true;
                }
            }
        }

        // return the largest i if true
        for (int i = M; i > 0; --i) {
            if (dp[N - 1][i - 1]) {
                return (i - 1);
            }
        }
        return 0;
    }
};

class Solution_1D {
public:
    /**
    * http://www.lintcode.com/en/problem/backpack/
    * @param m: An integer m denotes the size of a backpack
    * @param A: Given n items with size A[i]
    * @return: The maximum size
    */
    int backPack(int m, vector<int> A) {
        // write your code here
        if (A.empty() || m < 1) return 0;
        vector<int> dp(m + 1, 0);

        for (int i = 0; i < A.size(); i++) {
            for (int j = m; j >= 0; j--) {
                if (j >= A[i]) {
                    dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
                }
            }
        }

        return dp[m];
    }
};

/*
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);

    int rb = s.backPack(16, v);
    printf("%d", rb);

    printf("\n");
    system("pause");
    return 0;
}
*/