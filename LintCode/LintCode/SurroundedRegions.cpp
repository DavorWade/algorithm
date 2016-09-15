#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /**
    * @param board a 2D board containing 'X' and 'O'
    * @return void
    */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        if (board.empty()) return;
        queue<pair<int, int> > q;

        //elements in top and bottom row
        for (int i = 0; ;) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    q.push(make_pair(i, j));
                    board[i][j] = '#';

                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();

                        for (int t = 0; t < 4; t++) {
                            int xx = curr.first + x[t];
                            int yy = curr.second + y[t];

                            if (0 <= xx && xx < board.size() && 0 <= yy && yy < board[xx].size()) {
                                if (board[xx][yy] == 'O') {
                                    q.push(make_pair(xx, yy));
                                    board[xx][yy] = '#';
                                }
                            }
                        }

                    }
                }
            }

            if (i == board.size() - 1) break;
            else i = board.size() - 1;
        }

        //first, last element in each row
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; ;) {
                if (board[i][j] == 'O') {
                    q.push(make_pair(i, j));
                    board[i][j] = '#';

                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();

                        for (int t = 0; t < 4; t++) {
                            int xx = curr.first + x[t];
                            int yy = curr.second + y[t];

                            if (0 <= xx && xx < board.size() && 0 <= yy && yy < board[xx].size()) {
                                if (board[xx][yy] == 'O') {
                                    q.push(make_pair(xx, yy));
                                    board[xx][yy] = '#';
                                }
                            }
                        }
                    }
                }
                if (j == board[i].size() - 1) break;
                else j = board[i].size() - 1;
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

private:
    int x[4] = { -1, 0, 0, 1 };
    int y[4] = { 0, -1, 1, 0 };
};
