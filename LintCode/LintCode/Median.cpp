#include <stdlib.h>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param nums: A list of integers.
    * @return: An integer denotes the middle number of the array.
    */
    int median(vector<int> &nums) {
        // write your code here
        int left = 0;
        int right = nums.size();

        int k = -1;
        if (right % 2 == 1) k = right / 2;
        else k = right / 2 - 1;

        return select_kth(nums, left, right - 1, k);
    }

    int select_kth(vector<int> &nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int pivot = left + floor(rand() % (right - left + 1));

        pivot = partition(nums, left, right, pivot);
        if (pivot == k) return nums[k];
        else if (pivot < k) return select_kth(nums, pivot + 1, right, k);
        else return select_kth(nums, left, pivot - 1, k);
    }

    int partition(vector<int> &nums, int left, int right, int pivot) {
        int val = nums[pivot];
        swap(nums, pivot, right);
        int currIndex = left;

        for (int i = left; i < right; i++) {
            if (nums[i] < val) {
                swap(nums, currIndex, i);
                currIndex++;
            }
        }
        swap(nums, currIndex, right);

        return currIndex;
    }

    void swap(vector<int> &nums, int left, int right) {
        int tem = nums[left];
        nums[left] = nums[right];
        nums[right] = tem;
    }
};
