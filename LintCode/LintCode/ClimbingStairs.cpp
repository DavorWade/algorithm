#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param n: An integer
	* @return: An integer
	*/
	int climbStairs(int n) {
		// write your code here
		vector<int> rs(n + 1);
		rs[0] = 1;
		rs[1] = 1;

		for (int i = 2; i <= n; i++) {
			rs[i] = rs[i - 1] + rs[i - 2];
		}

		return rs[n];
	}
};
