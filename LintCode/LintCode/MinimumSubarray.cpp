#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param nums: a list of integers
    * @return: A integer denote the sum of minimum subarray
    */
    int minSubArray(vector<int> nums) {
        // write your code here
        int min_endding_here = nums[0];
        int min_so_far = nums[0];

        for (int i = 1;i < nums.size();i++) {
            min_endding_here = min(min_endding_here + nums[i], nums[i]);
            min_so_far = min(min_so_far, min_endding_here);
        }
        return min_so_far;
    }
};
