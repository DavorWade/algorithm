#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
	/**
	* @param nums: a vector of integers
	* @return: the maximum difference
	* @date: 2017-2-18
	*/
	int maximumGap(vector<int> nums) {
		// write your code here
		if (nums.size() < 2) return 0;

		int maxNum = nums[0];
		int minNum = nums[0];
		for (int i : nums) {
			maxNum = max(maxNum, i);
			minNum = min(minNum, i);
		}
		int len = (maxNum - minNum) / nums.size() + 1;

		vector<vector<int>> buckets((maxNum - minNum) / len + 1);
		for (int x : nums) {
			int i = (x - minNum) / len;
			if (buckets[i].empty()) {
				buckets[i].reserve(2);
				buckets[i].push_back(x);
				buckets[i].push_back(x);
			}
			else {
				if (x < buckets[i][0]) buckets[i][0] = x;
				if (x > buckets[i][1]) buckets[i][1] = x;
			}
		}

		int gap = 0;
		int prev = 0;
		for (int i = 1; i < buckets.size(); i++) {
			if (buckets[i].empty()) continue;
			gap = max(gap, buckets[i][0] - buckets[prev][1]);
			prev = i;
		}

		return gap;
	}

	//throw error: std::bad_alloc. Because when k is extremely large, the computer can allocate so much memory to vector count
	vector<int> countSort(vector<int> arr, int k) {
		vector<int> output(arr.size(), 0);
		vector<int> count(k + 1, 0);

		for (int i = 0; i < arr.size(); i++) count[arr[i]]++;

		for (int i = 1; i <= k; i++) count[i] += count[i - 1];

		for (int i = arr.size() - 1; i >= 0; i--) {
			output[count[arr[i]] - 1] = arr[i];
			count[arr[i]]--;
		}

		return output;
	}
};
