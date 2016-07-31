#include <stdlib.h>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param n, m: positive integer (1 <= n ,m <= 100)
    * @return an integer
    */
    int uniquePaths(int m, int n) {
        // wirte your code here
        vector<vector<int> > dp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
