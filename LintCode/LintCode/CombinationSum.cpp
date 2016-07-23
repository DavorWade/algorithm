#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param candidates: A list of integers
	* @param target:An integer
	* @return: A list of lists of integers
	*/
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// write your code here
		vector<vector<int> > rs;
		vector<int> combination;
		sort(candidates.begin(), candidates.end());

		helper(candidates, target, 0, 0, combination, rs);

		set<vector<int> > s(rs.begin(), rs.end());
		rs.assign(s.begin(), s.end());

		return rs;
	}

	bool helper(vector<int> &num, int target, int sum, int n, vector<int> combination, vector<vector<int> > &rs) {
		bool isCountSelf = false;
		vector<int> currCombination = combination;
		if (n == num.size()) {
			if (sum == target) {
				rs.push_back(combination);
				return true;
			}
			return false;
		}

		if (sum + num[n] < target || sum + num[n] == target) { //backtracking
			isCountSelf = true;
			currCombination.push_back(num[n]);
			if (sum + num[n] == target) {
				helper(num, target, sum + num[n], num.size(), currCombination, rs);
			}
			else {
				helper(num, target, sum + num[n], n, currCombination, rs);
			}
		}
		else {
			return false;
		}

		if (isCountSelf) currCombination.pop_back();
		helper(num, target, sum, n + 1, currCombination, rs);

		if (sum + num[n] < target || sum + num[n] == target) { //backtracking
			currCombination.push_back(num[n]);
			if (sum + num[n] == target) {
				helper(num, target, sum + num[n], num.size(), currCombination, rs);
			}
			else {
				helper(num, target, sum + num[n], n + 1, currCombination, rs);
			}
		}
	}
};