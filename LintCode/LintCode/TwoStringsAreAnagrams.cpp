#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param s: The first string
    * @param b: The second string
    * @return true or false
    */
    bool anagram(string s, string t) {
        // write your code here
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) return true;

        return false;
    }
};