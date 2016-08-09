#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param n: Given the range of numbers
    * @param k: Given the numbers of combinations
    * @return: All the combinations of k numbers out of 1..n
    */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > rs;
        if (n < k || n < 1 || k < 1) return rs;

        vector<bool> helper(n, false);
        fill(helper.begin(), helper.begin() + k, true);

        do {
            vector<int> tem;
            for (int i = 1; i <= n; i++) {
                if (helper[i - 1]) {
                    tem.push_back(i);
                }
            }

            rs.push_back(tem);
        } while (prev_permutation(helper.begin(), helper.end()));

        return rs;
    }
};
