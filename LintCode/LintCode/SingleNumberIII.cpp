#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

// O(n):https://fisherlei.blogspot.com/2015/10/leetcode-single-number-iii-solution.html

class Solution {
public:
    /**
    * @param A : An integer array
    * @return : Two integers
    * O(nlgn)
    */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        vector<int> rs;
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++) {
            if (i == A.size() - 1) {
                rs.push_back(A[i]);
                break;
            }
            if (A[i] != A[i + 1]) {
                rs.push_back(A[i]);
            }
            else {
                i++;
            }
        }

        return rs;
    }
};
