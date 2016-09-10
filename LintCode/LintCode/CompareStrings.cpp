#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param A: A string includes Upper Case letters
    * @param B: A string includes Upper Case letter
    * @return:  if string A contains all of the characters in B return true
    *           else return false
    */
    bool compareStrings(string A, string B) {
        // write your code here
        if (A.size() < B.size()) return false;
        if (B.size() == 0) return true;
        bool rs = false;

        vector<bool> isVisited(A.size(), false);
        for (int i = 0; i < B.size(); i++) {
            rs = false;
            string::size_type pos = A.find(B[i]);
            while (pos != string::npos) {
                if (!isVisited[pos]) {
                    isVisited[pos] = true;
                    rs = true;
                    break;
                }
                else {
                    pos = A.find(B[i], pos + 1);
                    rs = false;
                }
            }
            if (!rs) return false;
        }

        return rs;
    }
};