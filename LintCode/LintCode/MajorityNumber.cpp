#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: The majority number
	* @date: 2016.7.10
	*/
	int majorityNumber(vector<int> nums) {
		// write your code her
		int result = 0, count = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (count == 0){
				result = nums[i];
				count = 1;
			}
			else if (result == nums[i]) {
				count++;
			}
			else {
				count--;
			}
		}

		return result;
	}
};
