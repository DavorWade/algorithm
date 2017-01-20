#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
    * @param A an integer array sorted in ascending order
    * @param target an integer
    * @return an integer
    */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        int l = 0;
        int r = A.size();

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (A[mid] > target) {
                r = mid;
            }
            else if (A[mid] < target) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};
