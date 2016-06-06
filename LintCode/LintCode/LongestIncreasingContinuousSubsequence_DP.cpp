#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* http://www.lintcode.com/en/problem/longest-increasing-continuous-subsequence/
	* @param A an array of Integer
	* @return  an integer
	*/
	int longestIncreasingContinuousSubsequence(vector<int>& A) {
		// Write your code here
		int len = A.size();
		if (len < 2) return len;
		vector<int> dp(len + 1);
		int rs = 0;
		dp[0] = 1;

		for (int i = 1; i < len; i++) {
			dp[i] = A[i] > A[i - 1] ? dp[i - 1] + 1 : 1;
			rs = max(rs, dp[i]);
		}

		for (int i = 1; i < len; i++) {
			dp[i] = A[i] < A[i - 1] ? dp[i - 1] + 1 : 1;
			rs = max(rs, dp[i]);
		}
		return rs;
	}
};

int main(int argc, char *argv[]) {

	system("pause");
	return 0;
}