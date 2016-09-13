#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param n a positive integer
    * @return an integer
    * @date: 2016-9-13
    */
    int numSquares(int n) {
        // Write your code here
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 1;
        dp[1] = 1;
        vector<int> sqrNum;

        for (int i = 0; i <= n; i++) {
            if (pow(i, 2) <= n) sqrNum.push_back(pow(i, 2));
            else break;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = sqrNum.size() - 1; j >= 0; j--) {
                if (i == sqrNum[j]) dp[i] = 1;
                if (i > sqrNum[j]) {
                    dp[i] = min(dp[i], dp[i - sqrNum[j]] + dp[sqrNum[j]]);
                }
            }
        }

        return dp[n];
    }
};
