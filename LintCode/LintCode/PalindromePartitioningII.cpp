#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param s a string
	* @return an integer
	*/
	int minCut(string s) {
		// write your code here
		int len = s.size();
		vector<int> dp(len + 1, 0);
		vector<vector<bool> > isPalindrome(len, vector<bool>(len, false));

		//the worst case is cutting by each char
		for (int i = 0; i <= len; i++) {
			dp[i] = len - i;
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				isPalindrome[i][j] = false;
			}
		}

		for (int i = len - 1; i >= 0; i--) {
			for (int j = i; j < len; j++) {
				if (s[i] == s[j] && (j - i<2 || isPalindrome[i + 1][j - 1])) {
					isPalindrome[i][j] = true;
					dp[i] = min(dp[i], dp[j + 1] + 1);
				}
			}
		}

		return dp[0] - 1;
	}
};
