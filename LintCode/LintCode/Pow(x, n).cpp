#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    /**
    * @param x the base number
    * @param n the power number
    * @return the result
    */
    double myPow(double x, int n) {
        // Write your code here
        int nn = abs(n);
        if (x == 0) return 0;
        if (n == -1) return 1 / x;
        if (n == 0) return 1;
        if (n == 1) return x;

        double rs = myPow(x, nn / 2);
        rs *= rs;
        if (nn % 2) rs *= x;
        if (n < 0) rs = 1 / rs;

        return rs;
    }
};