#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param S, T: Two string.
    * @return: Count the number of distinct subsequences
    */
    int numDistinct(string &S, string &T) {
        // write your code here
        //¹ö¶¯Êý×é
        if (S.size() < T.size()) return 0;
        vector<int> dp(T.size() + 1, 0);
        dp[0] = 1;//used as a 

        for (int i = 1; i <= T.size(); i++) {
            dp[i] = 0;
        }
        for (int i = 1; i <= S.size(); i++) {
            for (int j = T.size(); j >= 1; j--) {
                if (S[i - 1] == T[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[T.size()];


		// 2-D array
        /*
		if (S.size() < T.size()) return 0;
        if (T.size() == 0) return 1;
        vector<vector<int> > dp(T.size() + 1, vector<int>(S.size() + 1, 0));
        for (int i = 0; i < S.size(); i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= S.size(); i++) {
            for (int j = 1; j <= T.size(); j++) {
                if (T[j - 1] == S[i - 1])
                    dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1];
                else
                    dp[j][i] = dp[j][i - 1];
            }
        }

        return dp[T.size()][S.size()];
        */
    }
};
