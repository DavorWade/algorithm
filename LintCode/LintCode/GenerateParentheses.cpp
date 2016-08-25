#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param n n pairs
    * @return All combinations of well-formed parentheses
    * http://www.lintcode.com/en/problem/generate-parentheses/#
    */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> rs;
        helper(rs, "(", n - 1, n);

        return rs;
    }

    void helper(vector<string> &rs, string ss, int left, int right) {
        if (left == 0 && right == 0) rs.push_back(ss);

        if (left > 0) {
            helper(rs, ss + "(", left - 1, right);
        }

        if (right > 0 && left < right) {
            helper(rs, ss + ")", left, right - 1);
        }
    }
};