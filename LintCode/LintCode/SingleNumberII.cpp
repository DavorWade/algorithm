#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.lintcode.com/en/problem/single-number-ii
class Solution {
public:
    /**
    * @param A : An integer array
    * @return : An integer
    */
    int singleNumberII(vector<int> &A) {
        // write your code here
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != A[i + 1]) return A[i];

            i += 2;
        }
        return INT_MIN;
    }
};
