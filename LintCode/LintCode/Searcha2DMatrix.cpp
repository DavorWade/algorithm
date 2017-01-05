#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param matrix, a list of lists of integers
    * @param target, an integer
    * @return a boolean, indicate whether matrix contains target
    */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.size() == 0) return false;
        int left = 0;
        int right = matrix.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] > target) {
                right = mid;
            }
            else if (matrix[mid][0] < target) {
                int k = matrix[mid].size() - 1;
                if (matrix[mid][k] < target) {
                    left = mid + 1;
                }
                else {
                    right = left = mid;
                }
            }
            else {
                return true;
            }
        }

        int m = right;
        left = 0;
        right = matrix[m].size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[m][mid] > target) {
                right = mid;
            }
            else if (matrix[m][mid] < target) {
                left = mid + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
