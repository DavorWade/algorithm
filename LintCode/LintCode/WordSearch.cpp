#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param board: A list of lists of character
    * @param word: A string
    * @return: A boolean
    */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        vector<vector<bool> > isVisited(board.size(), vector<bool>());
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                isVisited[i].push_back(false);
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    isVisited[i][j] = true;

                    if (dfs(board, i, j, word, 1, isVisited)) return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char> > &board, int i, int j, string word, int n, vector<vector<bool> > isVisited) {
        if (n == word.length()) {
            return true;
        }
        int x[4] = { 0, 0, -1, 1 };
        int y[4] = { -1, 1, 0, 0 };

        for (int k = 0; k < 4; k++) {
            int nx = i + x[k];
            int ny = j + y[k];

            if (0 <= nx && nx < board.size() && 0 <= ny && ny < board[nx].size()) {
                if (!isVisited[nx][ny]) {
                    if (board[nx][ny] == word[n]) {
                        isVisited[nx][ny] = true;

                        if (dfs(board, nx, ny, word, n + 1, isVisited)) return true;

                        isVisited[nx][ny] = false;
                    }
                }
            }
        }

        return false;
    }
};

/*
int main() {
    vector<vector<char> > board;
    board.push_back({ 'A', 'B', 'C', 'E' });
    board.push_back({ 'S', 'F', 'E', 'S' });
    board.push_back({ 'A', 'D', 'E', 'E' });

    Solution s;
    string ss = "ABCESEEEFS";
    bool rs = s.exist(board, ss);

    if (rs) printf("true\n");
    else printf("false\n");

    system("pause");
    return 0;
}
*/