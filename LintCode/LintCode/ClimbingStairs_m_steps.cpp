#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* A C program to count number of ways to reach n't stair when 
	* a person can climb 1, 2, ..m stairs at a time
	* @param n: An integer
	* @param m: [1,m] step at one time
	* @return: An integer
	*/
	int climbStairs(int n, int m) {
		// write your code here
		return countWaysUtil(n + 1, m);
	}

	// 
	int countWaysUtil(const int n, int m)
	{
		vector<int> res(n);
		res[0] = 1; 
		res[1] = 1;

		for (int i = 2; i<n; i++) {
			res[i] = 0;
			for (int j = 1; j <= m && j <= i; j++)
				res[i] += res[i - j];
		}

		return res[n - 1];
	}
};

int main(int argc, char *argv[]) {
	Solution solution;
	int n = 6, m = 4;
	printf("Nuber of ways = %d", solution.climbStairs(n, m));

	printf("\n");
	system("pause");
	return 0;
}