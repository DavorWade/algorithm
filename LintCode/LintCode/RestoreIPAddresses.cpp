#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
    * @param s the IP string
    * @return All possible valid IP addresses
    */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<string> res;
        getRes(s, "", res, 4);
        return res;
    }

    bool valid(string s) {
        if (s.size() == 3 && (atoi(s.c_str())>255 || atoi(s.c_str()) == 0)) {
            return false;
        }
        if (s.size() == 3 && s[0] == '0') {
            return false;
        }
        if (s.size() == 2 && atoi(s.c_str()) == 0) {
            return false;
        }
        if (s.size() == 2 && s[0] == '0') {
            return false;
        }

        return true;
    }

    void getRes(string s, string r, vector<string> &res, int k) {
        if (k == 0) {
            if (s.empty()) {
                res.push_back(r);
            }
            return;
        }
        else {
            for (int i = 1; i <= 3; i++) {
                if (s.size() >= i && valid(s.substr(0, i))) {
                    if (k == 1) {
                        getRes(s.substr(i), r + s.substr(0, i), res, k - 1);
                    }
                    else {
                        getRes(s.substr(i), r + s.substr(0, i) + ".", res, k - 1);
                    }
                }
            }
        }
    }
};
