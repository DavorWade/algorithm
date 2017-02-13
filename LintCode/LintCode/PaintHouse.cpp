#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param costs n x 3 cost matrix
	* @return an integer, the minimum cost to paint all houses
	*/
	int minCost(vector<vector<int>>& costs) {
		// Write your code here
		if (costs.size() < 1) return 0;
		vector<vector<int> > dp(costs.size(), vector<int>(3, INT_MAX));
		vector<vector<int> > used(costs.size(), vector<int>(3, 0));

		for (int i = 0; i < 3; i++) {
			dp[0][i] = costs[0][i];
			used[0][i] = i;
		}

		for (int i = 1; i < dp.size(); i++) {
			for (int k = 0; k < 3; k++) {
				for (int j = 0; j < 3; j++) {
					if (j != k && dp[i][k] > dp[i - 1][j] + costs[i][k]) {
						dp[i][k] = dp[i - 1][j] + costs[i][k];
					}
				}
			}
		}

		return min(dp[costs.size() - 1][0], min(dp[costs.size() - 1][1], dp[costs.size() - 1][2]));
	}
};
