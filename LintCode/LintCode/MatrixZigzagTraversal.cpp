#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> rs;
        if (matrix.size() == 0) {
            return rs;
        }
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int sum = rows + cols - 2;
        for (int k = 0; k <= sum; k++) {
            vector<int> tem;
            for (int i = 0; i < rows; i++) {
                int j = k - i;
                if (j >= 0 && j < cols) {
                    tem.push_back(matrix[i][j]);
                }
                else if (j < 0) {
                    break;
                }
                else {
                    continue;
                }
            }
            if (k % 2 == 0) {
                for (int t = tem.size() - 1; t >= 0; t--) {
                    rs.push_back(tem[t]);
                }
            }
            else {
                for (int t = 0; t < tem.size(); t++) {
                    rs.push_back(tem[t]);
                }
            }
        }
        
        return rs;
    }
};