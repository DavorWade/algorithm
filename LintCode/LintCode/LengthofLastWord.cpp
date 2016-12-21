#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    /**
    * @param s A string
    * @return the length of last word
    */
    int lengthOfLastWord(string& s) {
        // Write your code here
        if (s.size() < 1) return 0;
        vector<string> elems;
        split(s, ' ', elems);

        return elems[elems.size() - 1].size();
    }

    vector<string> &split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }

        return elems;
    }
};
