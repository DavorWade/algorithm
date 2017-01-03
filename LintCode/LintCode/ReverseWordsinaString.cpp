#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    /**
    * @param s : A string
    * @return : A string
    */
    string reverseWords(string s) {
        // write your code here
        s = trim(s);
        string rs = "";
        vector<string> elems;
        split(s, ' ', elems);
        if (elems.size() < 1) return s;

        for (int i = elems.size() - 1; i > 0; i--) {
            rs = rs + elems[i] + " ";
        }
        rs += elems[0];

        return rs;
    }

    void split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }

    string& trim(string &s) {
        if (s.empty()) {
            return s;
        }
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);

        return s;
    }
};
