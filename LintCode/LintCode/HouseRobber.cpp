#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param A: An array of non-negative integers.
	* return: The maximum amount of money you can rob tonight
	*/
	long long houseRobber(vector<int> A) {
		// write your code here
		vector<long long> dp(A.size() + 1, 0);
		dp[1] = A[0];

		for (int i = 2; i <= A.size(); i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + A[i - 1]);
		}

		return dp[A.size()];
	}
};
