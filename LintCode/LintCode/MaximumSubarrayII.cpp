#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

// O(n)
class Solution {
public:
    /**
    * @param nums: A list of integers
    * @return: An integer denotes the sum of max two non-overlapping subarrays
    */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int max_val = INT_MIN;
        vector<int> forward(nums.size() - 1, 0);
        vector<int> backword(nums.size() - 1, 0);
        forward_traversal(forward, nums);
        backward_traversal(backword, nums);

        for (int i = 0; i < nums.size() - 1; i++) {
            max_val = max(max_val, forward[i] + backword[i]);
        }

        return max_val;
    }

    void forward_traversal(vector<int> &forward, vector<int> &nums) {
        int max_endding_here = nums[0];
        int max_so_far = nums[0];
        forward[0] = nums[0];

        for (int i = 1; i < nums.size() - 1; i++) {
            max_endding_here = max(max_endding_here + nums[i], nums[i]);
            max_so_far = max(max_so_far, max_endding_here);
            forward[i] = max_so_far;
        }
    }

    void backward_traversal(vector<int> &backword, vector<int> &nums) {
        int max_endding_here = nums[nums.size() - 1];
        int max_so_far = nums[nums.size() - 1];
        backword[nums.size() - 2] = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i > 0; i--) {
            max_endding_here = max(max_endding_here + nums[i], nums[i]);
            max_so_far = max(max_so_far, max_endding_here);

            backword[i - 1] = max_so_far;
        }
    }
};


// O(n^2)
class Solution {
public:
    /**
    * @param nums: A list of integers
    * @return: An integer denotes the sum of max two non-overlapping subarrays
    */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int max_val = INT_MIN;

        for (int s = 1; s < nums.size(); s++) {
            int max_left = nums[0];
            int max_left_endding_here = nums[0];
            int max_right = nums[s];
            int max_right_endding_here = nums[s];

            for (int i = 1; i < s; i++) {
                max_left_endding_here = max(max_left_endding_here + nums[i], nums[i]);
                max_left = max(max_left, max_left_endding_here);
            }

            for (int j = s + 1; j < nums.size(); j++) {
                max_right_endding_here = max(max_right_endding_here + nums[j], nums[j]);
                max_right = max(max_right, max_right_endding_here);
            }

            max_val = max(max_val, max_left + max_right);
        }

        return max_val;
    }
};
