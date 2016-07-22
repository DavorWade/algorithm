#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	/**
	* @param num: Given the candidate numbers
	* @param target: Given the target number
	* @return: All the combinations that sum to target
	*/
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		// write your code here
		vector<vector<int> > rs;
		vector<int> combination;
		sort(num.begin(), num.end());

		helper(num, target, 0, 0, combination, rs);
		
		set<vector<int> > s(rs.begin(), rs.end());
		rs.assign(s.begin(), s.end());

		return rs;
	}

	bool helper(vector<int> &num, int target, int sum, int n, vector<int> combination, vector<vector<int> > &rs) {
		vector<int> currCombination = combination;
		if (n == num.size()) {
			if (sum == target) {
				rs.push_back(currCombination);
				return true;
			}
			return false;
		}

		helper(num, target, sum, n + 1, currCombination, rs);

		//if replace the next if clause with next 2 clause, it will be recursion/depth first search, time complexity = O(2^n), Time Limit Exceeded
		//currCombination.push_back(num[n]);
		//helper(num, target, sum + num[n], n + 1, currCombination, rs);
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

