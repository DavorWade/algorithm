#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
    * @param nums: a vector of integers
    * @return: an integer
    * //http://www.geeksforgeeks.org/find-the-missing-number//
    */
    int findMissing(vector<int> &nums) {
        // write your code here
        int x1 = nums[0]; /* For xor of all the elements in array */
        int x2 = 1; /* For xor of all the elements from 1 to n+1 */

        for (int i = 1; i < nums.size(); i++) {
            x1 = x1^nums[i];
        }

        for (int i = 2; i <= nums.size(); i++) {
            x2 = x2^i;
        }

        return (x1^x2);
    }
};

class Solution {
public:
    /**
    * @param nums: a vector of integers
    * @return: an integer
    * @date: 2016-11-3
    */
    int findMissing(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) return i;
        }

        return nums.size();
    }
};

class Solution {
public:
    /**
    * @param nums: a vector of integers
    * @return: an integer
    * @date: 2016-11-3
    */
    int findMissing(vector<int> &nums) {
        // write your code here
        int total = 0;
        int n = nums.size();
        total = ((n + 1) * n) / 2;

        for (int i = 0; i < n; i++) {
            total -= nums[i];
        }

        return total;
    }
};
