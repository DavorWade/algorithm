#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

//use codi of Permutations directly, then use a set<vector<int> > to remove duplicates.
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


//use a vector:used to record what number has been swaped.
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

        vector<int> curr;
        vector<int> used;
        dfs(nums, rs, curr, 0, nums.size() - 1, used);

        return rs;
    }

    void dfs(vector<int> nums, vector<vector<int> > &rs, vector<int> &curr, int start, int end, vector<int> used) {
        int n = end - start + 1;
        if (n == 2) {
            curr.push_back(nums[start]);
            curr.push_back(nums[end]);
            rs.push_back(curr);
            curr.pop_back();
            curr.pop_back();

            if (nums[end] != nums[start]) {
                curr.push_back(nums[end]);
                curr.push_back(nums[start]);
                rs.push_back(curr);
                curr.pop_back();
                curr.pop_back();
            }

            return;
        }
        else {
            for (int i = start; i < end + 1; i++) {
                if (find(used.begin(), used.end(), nums[i]) == used.end()) {
                    used.push_back(nums[i]);
                    vector<int> new_used;

                    vector<int> new_nums = swap_op(nums, start, i);
                    curr.push_back(new_nums[start]);
                    dfs(new_nums, rs, curr, start + 1, end, new_used);
                    curr.pop_back();
                }
            }
        }
    }

    vector<int> swap_op(vector<int> nums, int start, int i) {
        vector<int> new_nums(nums.begin(), nums.end());

        new_nums[start] = nums[i];
        new_nums[i] = nums[start];

        return new_nums;
    }
};
