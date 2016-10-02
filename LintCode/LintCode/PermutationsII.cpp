#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    /**
    * @param nums: A list of integers.
    * @return: A list of unique permutations.
    */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int> > rs;
        if (nums.size() < 1) {
            rs.push_back(vector<int>());
            return rs;
        }
        else if (nums.size() < 2) {
            rs.push_back(nums);
            return rs;
        }
        rs.push_back(vector<int>(1, nums[0]));

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < rs.size(); j++) {
                for (int k = 0; k < rs[j].size(); k++) {
                    vector<int> tem = rs[j];
                    tem.insert(tem.begin() + k, nums[i]);
                    rs.push_back(tem);
                }
                rs[j].push_back(nums[i]);
            }
        }

        set<vector<int> > helper(rs.begin(), rs.end());
        vector<vector<int> > allPer(helper.begin(), helper.end());

        return allPer;
    }
};
