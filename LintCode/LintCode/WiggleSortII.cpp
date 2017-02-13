#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param nums a list of integer
	* @return void
	*/
	void wiggleSort(vector<int>& nums) {
		// Write your code here
		vector<int> tmp = nums;
		int n = nums.size(), k = (n + 1) / 2, j = n;
		sort(tmp.begin(), tmp.end());

		for (int i = 0; i < n; ++i) {
			nums[i] = i & 1 ? tmp[--j] : tmp[--k];
		}
	}
};
