#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* http://www.lintcode.com/en/problem/backpack/
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @return: The maximum size
	*/
	int backPack(int m, vector<int> A) {
		// write your code here
		if (A.empty() || m < 1) return 0;
		const int N = A.size() + 1;
		const int M = m + 1;
		vector<vector<bool> > dp(N, vector<bool>(M, false));

		dp[0][0] = true;
		for (int i = 1; i != N; ++i) {
			for (int j = 0; j != M; ++j) {
				if (j < A[i - 1]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
				}
			}
		}

		// return the largest i if true
		for (int i = M; i > 0; --i) {
			if (dp[N - 1][i - 1]) {
				return (i - 1);
			}
		}
		return 0;
	}
};

/*
int main(int argc, char *argv[]) {
	Solution s;
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	int rb = s.backPack(14, v);
	printf("%d", rb);

	printf("\n");
	system("pause");
	return 0;
}
*/