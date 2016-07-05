#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A & V: Given n items with size A[i] and value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> A, vector<int> V) {
		// write your code here
		if (m < 1 || A.empty() || V.empty()) return 0;
		const int cols = m + 1;
		vector<int> dp(cols, 0);

		for (int i = 0; i < A.size(); i++) {
			for (int j = m; j >= 0; j--) {
				if (j >= A[i]) {
					dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
				}
			}
		}

		return dp[m];
	}
};