#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    *@param a, b: Two integer
    *return: An integer
    */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int count = 0;
        int c = a ^ b;

        int bits = 32;

        while (bits > 0) {
            if (c & 1) {
                count++;
            }
            c = c >> 1;

            bits--;
        }

        return count;
    }
};