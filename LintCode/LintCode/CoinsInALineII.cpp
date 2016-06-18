#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param values: a vector of integers
	* @return: a boolean which equals to true if the first player will win
	* dp[i]表示从i到end能取到的最大value
	* 2016-6-18
	*/
	bool firstWillWin(vector<int> &values) {
		// write your code here
		if (values.size() < 3) return true;
		int len = values.size();
		vector<int> dp(len, 0);
		int total = 0;

		dp[len - 1] = values[len - 1];
		dp[len - 2] = values[len - 2] + values[len - 1];
		for (int i = len - 3; i >= 0; i--) {
			int a = i + 4 <= len - 1 ? dp[i + 4] : 0;
			int b = i + 3 <= len - 1 ? dp[i + 3] : 0;
			int c = i + 2 <= len - 1 ? dp[i + 2] : 0;

			int value_take1coin = values[i] + min(b, c);
			int value_take2coins = values[i] + values[i + 1] + min(a, b);
			dp[i] = max(value_take1coin, value_take2coins);
		}

		for (int j = 0; j < len; j++) {
			total += values[j];
		}
		return dp[0] >(total - dp[0]) ? true : false;
	}
};