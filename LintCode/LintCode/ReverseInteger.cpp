#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
    * @param n the integer to be reversed
    * @return the reversed integer
    */
    int reverseInteger(int n) {
        // Write your code here
        string s = to_string(abs(n));
        string rs = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            rs += s[i];
        }
        try {
            int val = stoi(rs);
            if (n < 0) return -1 * val;
        }
        catch (const out_of_range& oor) {
            return 0;
        }

        return stoi(rs);
    }
};
