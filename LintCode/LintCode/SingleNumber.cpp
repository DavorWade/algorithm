#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param A: Array of integers.
	* return: The single number.
	*/
	int singleNumber(vector<int> &A) {
		// write your code here
		if (A.size() == 0) return 0;//提交时发现，如果为空需要返回“0”
		sort(A.begin(), A.end());
		for (int i = 0; i < A.size() - 1; i++) {
			if (A[i] == A[i + 1]) i++; //排序后，第奇数个数如果出现了两次，则与下一个数相同，直接判断下下个数即可；
			else return A[i];//否则，找到了目标数，返回
		}

		return A[A.size() - 1];
	}
};

