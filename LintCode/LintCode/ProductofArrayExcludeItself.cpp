#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
    * @param A: Given an integers array A
    * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
    */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> forward_vec(nums.size(), 1);
        vector<long long> backward_vec(nums.size(), 1);
        vector<long long> rs(nums.size(), 1);

        // forward_vec[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            forward(nums, forward_vec, i);
        }

        // backward_vec[backward_vec.size()-2] = nums[nums.size()-1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            backward(nums, backward_vec, i);
        }

        for (int i = 0; i < nums.size(); i++) {
            rs[i] = forward_vec[i] * backward_vec[i];
        }

        return rs;
    }

    void forward(vector<int> &nums, vector<long long> &forward_vec, int pos) {
        forward_vec[pos] = forward_vec[pos - 1] * nums[pos - 1];
    }

    void backward(vector<int> &nums, vector<long long> &backward_vec, int pos) {
        backward_vec[pos] = backward_vec[pos + 1] * nums[pos + 1];
    }
};
