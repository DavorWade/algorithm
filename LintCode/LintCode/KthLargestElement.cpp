#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    /*
    * param k : description of k
    * param nums : description of array and index 0 ~ n-1
    * return: description of return
    */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        return select_kth(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int select_kth(vector<int> &nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int pivot = left + floor(rand() % (right - left + 1));

        pivot = partition(nums, left, right, pivot);
        if (pivot == k) {
            return nums[k];
        }
        else if (pivot < k) {
            return select_kth(nums, pivot + 1, right, k);
        }
        else {
            return select_kth(nums, left, pivot - 1, k);
        }
    }

    int partition(vector<int> &nums, int left, int right, int pivot) {
        int val = nums[pivot];
        swap(nums, pivot, right);
        int currIndex = left;

        for (int i = left;i < right;i++) {
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
