#include <stdlib.h>
#include <stdint.h>
#include <vector>

using namespace std;

// O(n)
class Solution {
public:
    /**
    * @param nums: A list of integers
    * @return: The majority number occurs more than 1/3.
    */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int c1 = nums[0];
        int c2 = nums[0];
        int count1 = 0;
        int count2 = 0;

        for (auto num : nums) {
            if (!count1 || num == c1) {
                c1 = num;
                count1++;
            }
            else if (!count2 || num == c2) {
                c2 = num;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (auto num : nums) {
            if (num == c1) count1++;
            else if (num == c2) count2++;
        }

        return  count1 > count2 ? c1 : c2;
    }
};
