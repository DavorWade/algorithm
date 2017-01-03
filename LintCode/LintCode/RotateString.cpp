#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param str: a string
    * @param offset: an integer
    * @return: nothing
    */
    void rotateString(string &str, int offset) {
        //wirte your code here
        string s = trim(str);
        if (s == "") return;
        string tem = "";
        int n = offset % str.size();
        for (int i = 0; i < n; i++) {
            tem = str[str.size() - 1];
            str.insert(0, tem);
            str.erase(str.size() - 1);
        }
    }

    string& trim(string s) {
        if (s.empty()) {
            return s;
        }
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);

        return s;
    }
};
