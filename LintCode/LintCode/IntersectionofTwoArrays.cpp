#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    /**
    * @param nums1 an integer array
    * @param nums2 an integer array
    * @return an integer array
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        vector<int> rs;
        if (nums1.size() < 1 || nums2.size() < 1) return rs;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                rs.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        set<int> helper(rs.begin(), rs.end());
        rs.assign(helper.begin(), helper.end());

        return rs;
    }
};
