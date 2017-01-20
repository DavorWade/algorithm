#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param board: the board
    * @return: wether the Sudoku is valid
    */
    bool isValidSudoku(const vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    for (int t = 0; t < board[i].size(); t++) {
                        if (t != j) {
                            if (board[i][t] == board[i][j]) return false;
                        }
                    }

                    for (int t = 0; t < board.size(); t++) {
                        if (t != i) {
                            if (board[t][j] == board[i][j]) return false;
                        }
                    }

                    int row = (i / 3) * 3;
                    int col = (j / 3) * 3;
                    for (int t = row; t < row + 3; t++) {
                        for (int p = col; p < col + 3; p++) {
                            if (t != i && p != j) {
                                if (board[t][p] == board[i][j]) return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};
