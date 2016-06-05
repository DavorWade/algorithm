#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution{
public:
	/**
	* @param n: an integer
	* @return an integer f(n)
	*/
	//memorize,see lintcode-cpp.pdf 10.2.2 ±¸ÍüÂ¼·¨
	int fibonacci(int n) {
		// write your code here
		this->v = vector<int>(n, -1);
		v[0] = 0;
		v[1] = 1;

		return fibonacci_rc(n);
	}
private:
	vector<int> v;

	int fibonacci_rc(int n) {
		if (n == 1)
			return v[0];
		if (n == 2)
			return v[1];
		return getOrUpdate(n - 1) + getOrUpdate(n - 2);
	}

	int getOrUpdate(int n)
	{
		if (v[n - 1] != -1)
			return v[n - 1];
		else
			return v[n - 1] = fibonacci_rc(n);
	}
};

