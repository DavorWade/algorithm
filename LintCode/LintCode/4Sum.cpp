#include <stdlib.h>
#include <stdint.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param numbers: Give an array numbersbers of n integer
    * @param target: you need to find four elements that's sum of target
    * @return: Find all unique quadruplets in the array which gives the sum of
    *          zero.
    */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code herej;
        sort(nums.begin(), nums.end());
        vector<vector<int> > rs;
        auto last = nums.end();

        for (auto i = nums.begin(); i < last - 3; ++i) {
            if (i > nums.begin() && *i == *(i - 1)) continue;

            for (auto j = i + 1; j < last - 2; ++j) {
                if (j > i + 1 && *j == *(j - 1)) continue;

                auto m = j + 1;
                auto k = last - 1;
                while (m < k) {
                    if (*i + *j + *m + *k < target) {
                        m++;
                        while (*m == *(m - 1) && m < k) m++;
                    }
                    else if (*i + *j + *m + *k > target) {
                        k--;
                        while (*k == *(k + 1) && m < k) k--;
                    }
                    else {
                        rs.push_back({ *i, *j, *m, *k });
                        m++;
                        k--;
                        while (*m == *(m - 1) && *k == *(k + 1) && m < k) {
                            m++;
                            k--;
                        }
                    }
                }
            }
        }
        //sort(rs.begin(), rs.end());
        //rs.erase(unique(rs.begin(), rs.end()), rs.end());

        return rs;
    }
};

