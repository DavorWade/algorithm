#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param A, B: Two strings.
    * @return: The length of longest common subsequence of A and B.
    */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        vector<vector<int> > dp(A.size() + 1, vector<int>(B.size() + 1, 0));

        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                int same = 0;
                if (A[i - 1] == B[j - 1]) same = 1;
                if (same == 1) dp[i][j] = dp[i - 1][j - 1] + same;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[A.size()][B.size()];
    }
};
