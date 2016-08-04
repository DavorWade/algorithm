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
    * @param numbers : Give an array numbers of n integer
    * @return : Find all unique triplets in the array which gives the sum of zero.
    * @date: 2016-8-5
    * @Complexcity: O(n) Space, O(n^2logn) Time
    */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > rs;
        set<vector<int> > helper;
        map<int, int> hashData;

        for (int i = 0; i < nums.size(); i++) {
            hashData[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int tem = 0 - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int temp = tem - nums[j];
                if (hashData.find(temp) != hashData.end()) {
                    if (hashData[temp] != i && hashData[temp] != j) {
                        vector<int> te;
                        te.push_back(nums[i]);
                        te.push_back(nums[j]);
                        te.push_back(temp);
                        rs.push_back(te);
                    }
                }
            }
        }

        for (int i = 0; i < rs.size(); i++) {
            vector<int> tem = rs[i];
            sort(tem.begin(), tem.end());

            helper.insert(tem);
        }

        return vector<vector<int> >(helper.begin(), helper.end());
    }
};
