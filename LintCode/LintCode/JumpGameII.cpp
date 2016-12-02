#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param A: A list of lists of integers
    * @return: An integer
    */
    int jump(vector<int> A) {
        // wirte your code here
        int curr_index = A.size() - 1;
        int jump_count = 0;

        while (curr_index > 0) {
            int dist = 1;
            for (int i = curr_index - 1; i >= 0; i--, dist++) {
                if (A[i] >= dist) {
                    curr_index = i;
                }
            }
            jump_count++;
        }

        return jump_count;
    }
};