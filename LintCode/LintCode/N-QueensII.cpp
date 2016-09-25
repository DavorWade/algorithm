#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
    * Calculate the total number of distinct N-Queen solutions.
    * @param n: The number of queens.
    * @return: The total number of distinct solutions.
    */
    int totalNQueens(int n) {
        // write your code here
        int rs = 0;
        vector<int> col;

        solveNQ(n, 0, rs, col);

        return rs;
    }

    void solveNQ(int n, int currRow, int &rs, vector<int> &col) {
        if (currRow == n) {
            rs++;
            return;
        }

        for (int currCol = 0; currCol < n; currCol++) {
            if (isValid(currRow, currCol, col)) {
                col.push_back(currCol);

                solveNQ(n, currRow + 1, rs, col);

                col.pop_back();
            }
        }
    }

    bool isValid(int currRow, int currCol, vector<int> &col) {
        if (currRow < col.size()) return false;

        for (int i = 0; i < col.size(); i++) {
            if (currCol == col[i] || abs(currRow - i) == abs(currCol - col[i])) return false;
        }

        return true;
    }
};
