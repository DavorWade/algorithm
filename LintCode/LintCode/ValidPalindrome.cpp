#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

class Solution {
public:
    /**
    * @param s A string
    * @return Whether the string is a valid palindrome
    */
    bool isPalindrome(string& s) {
        // Write your code here
        char alp[35] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        vector<char> t(alp, alp + 35);
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        string rs = "";
        for (int i = 0; i < s.size(); i++) {
            if (find(t.begin(), t.end(), s[i]) != t.end()) {
                rs += s[i];
            }
        }

        string tem = rs;
        reverse(tem.begin(), tem.end());
        if (rs == tem) return true;

        return false;
    }
};
