#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param nums: a vector of integers
    * @return: return nothing (void), do not return anything, modify nums in-place instead
    * @date: 2017-1-20
    */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        if (nums.size() < 2) return;

        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        int j = i + 1;
        while (j < nums.size() && nums[j] > nums[i]) j++;
        j--;

        swap(nums[i], nums[j]);
        sort(nums.begin() + i + 1, nums.end());
    }
};
