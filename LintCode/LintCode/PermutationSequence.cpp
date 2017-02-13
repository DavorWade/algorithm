#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param n: n
	* @param k: the kth permutation
	* @return: return the k-th permutation
	*/
	string getPermutation(int n, int k) {
		string rs;
		vector<int> factorial(n, 1);
		vector<char> num(n, 1);

		for (int i = 1; i < n; i++) {
			factorial[i] = factorial[i - 1] * i;
		}

		for (int i = 0; i < n; i++) {
			num[i] = (i + 1) + '0';
		}

		k--;
		for (int i = n; i >= 1; i--) {
			int j = k / factorial[i - 1];
			k %= factorial[i - 1];
			rs.push_back(num[j]);
			num.erase(num.begin() + j);
		}

		return rs;
	}
};
