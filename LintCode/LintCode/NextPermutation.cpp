#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param nums: An array of integers
    * @return: An array of integers that's next permuation
    * @date: 2017-1-20
    */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return nums;

        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return nums;
        }

        int j = i + 1;
        while (j < nums.size() && nums[j] > nums[i]) j++;
        j--;

        swap(nums[i], nums[j]);
        sort(nums.begin() + i + 1, nums.end());

        return nums;
    }
};
