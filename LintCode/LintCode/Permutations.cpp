#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

//without using recursion
//
class Solution {
public:
    /**
    * @param nums: A list of integers.
    * @return: A list of permutations.
    * @date: 2016-10-2
    */
    vector<vector<int> > permute(vector<int> nums) {
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
            int n = rs.size();
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < rs[j].size(); k++) {
                    vector<int> per = rs[j];
                    per.insert(per.begin() + k, nums[i]);
                    rs.push_back(per);
                }
                rs[j].push_back(nums[i]);
            }
        }
        return rs;
    }
};


//recursion
class Solution {
public:
    /**
    * @param nums: A list of integers.
    * @return: A list of permutations.
    * @date: 2016-10-2
    */
    vector<vector<int> > permute(vector<int> nums) {
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
        dfs(nums, rs, curr, 0, nums.size() - 1);

        return rs;
    }

    void dfs(vector<int> nums, vector<vector<int> > &rs, vector<int> &curr, int start, int end) {
        int n = end - start + 1;
        if (n == 2) {
            curr.push_back(nums[start]);
            curr.push_back(nums[end]);
            rs.push_back(curr);
            curr.pop_back();
            curr.pop_back();

            curr.push_back(nums[end]);
            curr.push_back(nums[start]);
            rs.push_back(curr);
            curr.pop_back();
            curr.pop_back();

            return;
        }
        else {
            for (int i = start; i < end + 1; i++) {
                vector<int> new_nums = swap_op(nums, start, i);
                curr.push_back(new_nums[start]);
                dfs(new_nums, rs, curr, start + 1, end);
                curr.pop_back();
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
