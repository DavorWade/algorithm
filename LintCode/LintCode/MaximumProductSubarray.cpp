#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param nums: a vector of integers
	* @return: an integer
	*/
	int maxProduct(vector<int>& nums) {
		// write your code here
		if (nums.size() < 1) return 0;

		int ret, curMax, curMin;
		ret = curMax = curMin = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			int temp = curMax;
			curMax = max(max(curMax * nums[i], curMin * nums[i]), nums[i]);
			curMin = min(min(temp * nums[i], curMin * nums[i]), nums[i]);
			ret = max(ret, curMax);
		}

		return ret;
	}
};