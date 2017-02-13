#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integer which is 0, 1 or 2
	* @return: nothing
	*/
	void sortColors(vector<int> &nums) {
		// write your code here
		quickSort(nums, 0, nums.size());
	}

	void quickSort(vector<int> &nums, int l, int r) {
		if (l < r) {
			int pivot = partition(nums, l, r);

			quickSort(nums, l, pivot);
			// quickSort(nums, pivot, r); is wrong
			quickSort(nums, pivot + 1, r);
		}
	}

	int partition(vector<int> &nums, int l, int r) {
		int mid = l + (r - l) / 2;
		int pivot_val = nums[mid];
		nums[mid] = nums[r - 1];
		nums[r - 1] = pivot_val;

		int pivot = l - 1;
		for (int j = l; j < r - 1; j++) { // j < r-1, not j < r
			if (nums[j] <= pivot_val) {
				pivot++;
				swap(nums[j], nums[pivot]); // swap()会改变vector的值
			}
		}

		pivot++;
		swap(nums[r - 1], nums[pivot]);

		return pivot;
	}
};