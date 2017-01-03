#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
    /**
    * param A : an integer sorted array
    * param target :  an integer to be inserted
    * return : an integer
    */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.empty() || A[0] > target) return 0;
        if (A[A.size() - 1] < target) return A.size();

        int left = 0;
        int right = A.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return right;
    }
};
