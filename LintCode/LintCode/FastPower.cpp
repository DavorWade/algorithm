#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*
	* @param a, b, n: 32bit integers
	* @return: An integer
	* (a * b) % p = (a % p * b % p) % p,
	* 将 a^n % b 分解为:
	* (a^(n/2) * a^(n/2) * (a)) %b = ((a^(n/2) * a^(n/2))%b * (a)%b) %b = ((a^(n/2)%b * a^(n/2)%b)%b * (a)%b) %b
	*/
	int fastPower(int a, int b, int n) {
		// write your code here
		if (a == 0) return 0;
		if (n == 0) return 1 % b;
		if (n == 1) return a % b;

		long rs = fastPower(a, b, n / 2);
		rs *= rs;

		rs %= b;

		if (n % 2 != 0) rs = rs * (a % b);

		rs %= b;

		return (int)rs;
	}
};
