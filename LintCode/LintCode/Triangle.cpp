#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
	/**
	* @param triangle: a list of lists of integers.
	* @return: An integer, minimum path sum.
	*/
	int minimumTotal(vector<vector<int> > &triangle) {
		// write your code here
		const int rows = triangle.size();
		vector<int> dp(rows, 0);
		for (int i = 0; i < rows; i++) {
			dp[i] = triangle[rows - 1][i];
		}
		for (int i = rows - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
			}
		}

		return dp[0];
	}
};
