#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
    * Determine whether s3 is formed by interleaving of s1 and s2.
    * @param s1, s2, s3: As description.
    * @return: true of false.
    * @date: 2016-12-19
    * dfs can also be applied.
    */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (s3.size() != s1.size() + s2.size()) return false;

        vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, true));

        for (int i = 1; i <= len1; i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int j = 1; j <= len2; j++) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                bool case1 = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                bool case2 = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                dp[i][j] = case1 || case2;
            }
        }

        return dp[len1][len2];
    }
};