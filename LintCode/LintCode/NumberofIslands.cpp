#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
    * @param grid a boolean 2D matrix
    * @return an integer
    */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<bool>>& grid, int i, int j) {
        if (!grid[i][j]) return;

        grid[i][j] = false;
        for (int t = 0; t < 4; t++) {
            int xx = i + x[t];
            int yy = j + y[t];

            if (0 <= xx && xx < grid.size() && 0 <= yy && yy < grid[i].size()) {
                dfs(grid, xx, yy);
            }
        }
    }

private:
    int x[4] = { 0, 0, -1, 1 };
    int y[4] = { -1, 1, 0, 0 };
};