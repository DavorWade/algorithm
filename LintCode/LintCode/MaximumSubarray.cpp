#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param nums: A list of integers
    * @return: A integer indicate the sum of max subarray
    */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int max_endding_here = nums[0];
        int max_so_far = nums[0];

        for (int i = 1;i < nums.size();i++) {
            max_endding_here = max(max_endding_here + nums[i], nums[i]);
            max_so_far = max(max_so_far, max_endding_here);
        }
        return max_so_far;
    }
};
