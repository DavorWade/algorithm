#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param nums: A list of integers
    * @return: An integer indicate the value of maximum difference between two
    *          Subarrays
    */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int rs = INT_MIN;
        vector<int> forward_min(nums.size() - 1, 0);
        vector<int> forward_max(nums.size() - 1, 0);
        vector<int> backward_min(nums.size() - 1, 0);
        vector<int> backward_max(nums.size() - 1, 0);

        forward_min_val(forward_min, nums);
        forward_max_val(forward_max, nums);
        backward_min_val(backward_min, nums);
        backward_max_val(backward_max, nums);

        for (int i = 1; i < nums.size(); i++) {
            rs = max(rs, abs(forward_max[i - 1] - backward_min[i - 1]));
        }

        for (int i = 1; i < nums.size(); i++) {
            rs = max(rs, abs(forward_min[i - 1] - backward_max[i - 1]));
        }

        return rs;
    }

    void forward_min_val(vector<int> &v, vector<int> &nums) {
        int min_endding_here = nums[0];
        int min_so_far = nums[0];
        v[0] = min_so_far;

        for (int i = 2; i < nums.size(); i++) {
            min_endding_here = min(min_endding_here + nums[i - 1], nums[i - 1]);
            min_so_far = min(min_so_far, min_endding_here);

            v[i - 1] = min_so_far;
        }
    }

    void forward_max_val(vector<int> &v, vector<int> &nums) {
        int max_endding_here = nums[0];
        int max_so_far = nums[0];
        v[0] = max_so_far;

        for (int i = 2; i < nums.size(); i++) {
            max_endding_here = max(max_endding_here + nums[i - 1], nums[i - 1]);
            max_so_far = max(max_so_far, max_endding_here);

            v[i - 1] = max_so_far;
        }
    }

    void backward_min_val(vector<int> &v, vector<int> &nums) {
        int min_endding_here = nums[nums.size() - 1];
        int min_so_far = nums[nums.size() - 1];
        v[nums.size() - 2] = min_so_far;

        for (int i = nums.size() - 2; i > 0; i--) {
            min_endding_here = min(min_endding_here + nums[i], nums[i]);
            min_so_far = min(min_so_far, min_endding_here);

            v[i - 1] = min_so_far;
        }
    }

    void backward_max_val(vector<int> &v, vector<int> &nums) {
        int max_endding_here = nums[nums.size() - 1];
        int max_so_far = nums[nums.size() - 1];
        v[nums.size() - 2] = max_so_far;

        for (int i = nums.size() - 2; i > 0; i--) {
            max_endding_here = max(max_endding_here + nums[i], nums[i]);
            max_so_far = max(max_so_far, max_endding_here);

            v[i - 1] = max_so_far;
        }
    }
};
