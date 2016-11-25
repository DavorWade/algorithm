#include <stdlib.h>
#include <stdio.h>
#include <vector>


using namespace std;

class Solution {
public:
    /**
    * @param A: A list of integers
    * @return: The boolean answer
    */
    bool canJump(vector<int> A) {
        // write you code here
        if (A.size() == 1) return true;
        bool rs = false;
        int dis = 1;
        for (int i = A.size() - 2; i >= 0; i--) {
            if (A[i] >= dis) {
                rs = true;
                dis = 1;
            }
            else {
                rs = false;
                dis++;
            }
        }

        return rs;
    }
};
