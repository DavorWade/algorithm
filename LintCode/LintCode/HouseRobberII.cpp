#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param nums: An array of non-negative integers.
	* return: The maximum amount of money you can rob tonight
	*/
	int houseRobber2(vector<int>& nums) {
		// write your code here
		if (nums.size() < 1) return 0;
		if (nums.size() < 2) return nums[0];

		vector<int> dp_rob_firsh(nums.size(), 0); //from 0 to nums.size()-2
		dp_rob_firsh[1] = nums[0];
		vector<int> dp_no_first(nums.size(), 0); //from 1 to nums.size()-1
		dp_no_first[1] = nums[1];

		for (int i = 2; i < nums.size(); i++) {
			dp_rob_firsh[i] = max(dp_rob_firsh[i - 1], dp_rob_firsh[i - 2] + nums[i - 1]);

			dp_no_first[i] = max(dp_no_first[i - 1], dp_no_first[i - 2] + nums[i]);
		}

		return max(dp_rob_firsh[nums.size() - 1], dp_no_first[nums.size() - 1]);
	}
};
