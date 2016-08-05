#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param numbers: Give an array numbers of n integer
    * @param target: An integer
    * @return: return the sum of the three integers, the sum closest target.
    */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int rs;
        auto last = nums.end();

        for (auto i = nums.begin(); i < last - 2; ++i) {
            auto j = i + 1;
            if (i > nums.begin() && *i == *(i - 1)) continue;
            auto k = last - 1;
            while (j < k) {
                if (*i + *j + *k < target) {
                    int tem = abs(*i + *j + *k - target);
                    if (tem < closest) {
                        closest = tem;
                        rs = *i + *j + *k;
                    }
                    ++j;
                    while (*j == *(j - 1) && j < k) ++j;
                }
                else if (*i + *j + *k > target) {
                    int tem = abs(*i + *j + *k - target);
                    if (tem < closest) {
                        closest = tem;
                        rs = *i + *j + *k;
                    }

                    --k;
                    while (*k == *(k + 1) && j < k) --k;
                }
                else {
                    int tem = abs(*i + *j + *k - target);
                    if (tem < closest) {
                        closest = tem;
                        rs = *i + *j + *k;
                    }

                    ++j;
                    --k;
                    while (*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
                }
            }
        }
        return rs;
    }
};
