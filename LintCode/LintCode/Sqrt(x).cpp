#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
    * @param x: An integer
    * @return: The sqrt of x
    */
    int sqrt(int x) {
        // write your code here
        int left = 0;
        int right = x / 2 + 1; // 包前不包后

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (pow(mid, 2) > x) {
                right = mid;
            }
            else if (pow(mid, 2) < x) {
                if (pow(mid + 1, 2) > x) return mid;
                left = mid + 1;
            }
            else {
                return mid;
            }
        }

        return right;
    }
};
