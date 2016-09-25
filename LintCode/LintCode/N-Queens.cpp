#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
    * Get all distinct N-Queen solutions
    * @param n: The number of queens
    * @return: All distinct solutions
    * For example, A string '...Q' shows a queen on forth position
    */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string> > allSol;
        vector<string> sol;
        vector<int> col;

        solveNQ(n, 0, col, sol, allSol);

        return allSol;
    }

    void solveNQ(int rows, int currRow, vector<int> &col, vector<string> &sol, vector<vector<string> > &allSol) {
        if (rows == currRow) {
            allSol.push_back(sol);
            return;
        }

        for (int i = 0; i < rows; i++) {
            if (isValid(currRow, i, col)) {
                string s(rows, '.');
                s[i] = 'Q';

                sol.push_back(s);
                allSol.push_back(sol);
                col.push_back(i);

                solveNQ(rows, currRow + 1, col, sol, allSol);
                sol.pop_back();
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
