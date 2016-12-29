#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    /**
    * @param word1 & word2: Two string.
    * @return: The minimum number of steps.
    */
    int minDistance(string word1, string word2) {
        // write your code here
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > f(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            f[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            f[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                }
                else {
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                }
                // f[i][j] = min(f[i-1][j], f[i][j-1]) + 1;
                // f[i][j] = min(f[i][j], word1[i-1] == word2[j-1] ? f[i-1][j-1] : f[i-1][j-1]+1);
            }
        }
        return f[m][n];
    }
};
