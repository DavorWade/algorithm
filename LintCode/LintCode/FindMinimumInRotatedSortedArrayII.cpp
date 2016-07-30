#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param num: the rotated sorted array
	* @return: the minimum number in the array
	*/
	int findMin(vector<int> &num) {
		// write your code here
		if (num.size() == 1) {
			return num[0];
		}

		if (num.size() > 1) {
			return binarySearch(num, 0, num.size() - 1);
		}

		return -1;
	}

	int binarySearch(vector<int> &num, int start, int end) {
		if (end - start == 1) {
			return num[start] < num[end] ? num[start] : num[end];
		}

		if (end > start) {
			int middle = (end - start) / 2 + start;
			int left = binarySearch(num, start, middle - 1);
			int right = binarySearch(num, middle, end);
			return left < right ? left : right;
		}

		return num[start];
	}
};
