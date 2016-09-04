#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution{
public:
    /**
    * @param nums an integer array and all positive numbers, no duplicates
    * @param target an integer
    * @return an integer
    * @date: 2016-9-4
    */
    int backPackVI(vector<int>& nums, int target) {
        // Write your code here
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};