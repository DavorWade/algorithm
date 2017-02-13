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
	* @date: 2017-2-7
	*/
	void wiggleSort(vector<int>& nums) {
		// Write your code here
		sort(nums.begin(), nums.end());
		if (nums.size() <= 2) return;

		for (int i = 2; i < nums.size(); i += 2) {
			swap(nums[i], nums[i - 1]);
		}
	}
};
