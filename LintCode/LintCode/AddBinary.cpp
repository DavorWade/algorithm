#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
    * @param a a number
    * @param b a number
    * @return the result
    */
    string addBinary(string& a, string& b) {
        // Write your code here
        string rs;
        int carry = 0;

        for (int i = a.size() - 1, j = b.size() - 1;i >= 0 || j >= 0;i--, j--) {
            int ai = i >= 0 ? a[i] - '0' : 0;
            int bj = j >= 0 ? b[j] - '0' : 0;
            int val = (ai + bj + carry) % 2;
            carry = (ai + bj + carry) / 2;
            rs.insert(rs.begin(), val + '0');
        }

        if (carry > 0) {
            rs.insert(rs.begin(), carry + '0');
        }

        return rs;
    }
};