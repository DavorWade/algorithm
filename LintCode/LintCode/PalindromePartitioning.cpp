#include <stdlib.h>
#include <stdint.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param s: A string
    * @return: A list of lists of string
    */
    vector<vector<string> > partition(string s) {
        // write your code here
        vector<vector<string>> rs;
        vector<string> path;

        dfs(rs, path, s, 0);

        return rs;
    }

    void dfs(vector<vector<string> > &rs, vector<string> &path, const string &s, int start) {
        if (start == s.size()) {
            rs.push_back(path);
            return;
        }

        for (int i = start; i<s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(rs, path, s, i + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            start++;
            end--;
        }

        return start >= end;
    }
};
