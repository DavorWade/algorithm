#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param num an integer
    * @return true if num is an ugly number or false
    * @date: 2017-1-6
    */
    bool isUgly(int num) {
        // Write your code here
        if (num == 1) return true;
        if (num % 7 == 0) return false;

        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            }
            else if (num % 3 == 0) {
                num /= 3;
            }
            else if (num % 5 == 0) {
                num /= 5;
            }
            else {
                break;
            }
        }

        if (num != 1) return false;

        return true;
    }
};