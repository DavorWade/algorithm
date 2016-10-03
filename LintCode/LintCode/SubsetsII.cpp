#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param S: A set of numbers.
    * @return: A list of lists. All valid subsets.
    */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        int n = S.size();
        vector<vector<int> > allSubsets;

        vector<int> nums(S.begin(), S.end());
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= n; i++) {
            vector<vector<int> > combination = getCombination(n, i);

            for (int j = 0; j < combination.size(); j++) {
                vector<int> tem;
                for (int k = 0; k < combination[j].size(); k++) {
                    tem.push_back(nums[combination[j][k]]);
                }
                allSubsets.push_back(tem);
            }
        }
        allSubsets.push_back(vector<int>());

        set<vector<int> > helper(allSubsets.begin(), allSubsets.end());
        allSubsets.assign(helper.begin(), helper.end());

        return allSubsets;
    }

    vector<vector<int> > getCombination(int n, int r) {
        vector<vector<int> > combination;
        vector<bool> v(n);
        fill(v.begin(), v.begin() + r, true);

        do {
            vector<int> tem;
            for (int i = 0; i < n; i++) {
                if (v[i]) {
                    tem.push_back(i);
                }
            }

            if (!tem.empty()) combination.push_back(tem);
        } while (prev_permutation(v.begin(), v.end()));

        return combination;
    }
};
