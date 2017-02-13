#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param matrix: a matrix of 0 and 1
	* @return: an integer
	*/
	int maxSquare(vector<vector<int> > &matrix) {
		// write your code here
		vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		int max_square = 0;

		for (int i = 0; i < matrix.size(); i++) {
			dp[i][0] = matrix[i][0];
			max_square = max(max_square, matrix[i][0]);
		}
		for (int j = 0; j < matrix[0].size(); j++) {
			dp[0][j] = matrix[0][j];
			max_square = max(max_square, matrix[0][j]);
		}

		for (int i = 1; i < matrix.size(); i++) {
			for (int j = 1; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) {
					dp[i][j] = 0;
				}
				else {
					int top_left = dp[i - 1][j - 1];
					int left = dp[i][j - 1];
					int top = dp[i - 1][j];

					int min_val = min(top_left, min(left, top));
					dp[i][j] = min_val + 1;

					max_square = max(max_square, dp[i][j]);
				}
			}
		}

		return max_square*max_square;
	}
};
