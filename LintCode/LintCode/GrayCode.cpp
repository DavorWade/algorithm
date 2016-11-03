#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param n a number
    * @return Gray code
    */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> rs;
        if (n < 0) return rs;
        rs.push_back(0);

        for (int i = 0; i < n; i++) {
            int highestBit = 1 << i;
            for (int j = rs.size() - 1; j >= 0; j--) {
                rs.push_back(rs[j] + highestBit);
            }
        }

        return rs;
    }
};
