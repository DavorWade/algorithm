#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A list of integers includes the index of the first number
	*          and the index of the last number
	* @date: 2017-2-12
	*/

	struct node {
		node(int _value, int _pos) :value(_value), pos(_pos) {}
		int value, pos;
		bool operator<(const node &o) const {
			return value < o.value;
		}
	};

	vector<int> subarraySumClosest(vector<int> nums) {
		// write your code here
		vector<node> s;
		vector<int> results(2);
		s.push_back(node(0, -1));

		int sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			s.push_back(node(sum, i));
		}

		sort(s.begin(), s.end());
		int ans = 0x7fffffff;
		for (int i = 0; i < s.size() - 1; ++i) {
			if (abs(s[i + 1].value - s[i].value) < ans) {
				ans = abs(s[i + 1].value - s[i].value);
				results[0] = min(s[i].pos, s[i + 1].pos) + 1;
				results[1] = max(s[i].pos, s[i + 1].pos);
			}
		}

		return results;
	}
};
