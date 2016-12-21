#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param A: An integer array.
    * @param target: An integer.
    */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        vector<vector<int> > dp(A.size(), vector<int>(100, INT_MAX));
        int rs = INT_MAX;

        for (int i = 0; i < dp.size(); i++) {
            for (int j = 1; j <= 100; j++) {
                if (i == 0) {
                    dp[i][j - 1] = abs(j - A[i]);
                }
                else {
                    for (int k = 1; k <= 100; k++) {
                        if (abs(j - k) <= target) {
                            dp[i][j - 1] = min(dp[i][j - 1], abs(j - A[i]) + dp[i - 1][k - 1]);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 100; i++) {
            rs = min(rs, dp[dp.size() - 1][i]);
        }
        return rs;
    }
};
