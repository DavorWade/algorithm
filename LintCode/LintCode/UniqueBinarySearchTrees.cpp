#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
    * @paramn n: An integer
    * @return: An integer
    */
    int numTrees(int n) {
        // write your code here
        vector<int> nums(n + 1, 0);
        nums[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                nums[i] += nums[j] * nums[i - 1 - j];
            }
        }

        return nums[n];
    }
};
