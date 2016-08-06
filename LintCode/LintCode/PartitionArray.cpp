#include <stdlib.h>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            while (left <= right && nums[left] < k) left++;
            while (left <= right && nums[right] >= k) right--;
            if (left <= right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;

                left++;
                right--;
            }
        }

        return left;
    }
};
