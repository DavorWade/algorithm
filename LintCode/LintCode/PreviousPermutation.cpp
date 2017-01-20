#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param nums: An array of integers
    * @return: An array of integers that's previous permuation
    * @date: 2017-1-20
    */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return nums;

        int i = nums.size() - 2;
        while (i >= 0 && nums[i] <= nums[i + 1]) i--;
        if (i < 0) {
            sort(nums.begin(), nums.end(), greater<int>());
            return nums;
        }

        int j = i + 1;
        while (j < nums.size() && nums[i] > nums[j]) j++;
        j--;

        swap(nums[i], nums[j]);
        sort(nums.begin() + i + 1, nums.end(), greater<int>());

        return nums;
    }
};
