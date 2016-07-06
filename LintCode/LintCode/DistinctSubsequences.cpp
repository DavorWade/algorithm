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
	}
};
