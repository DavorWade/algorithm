#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
    * @param nums: The integer array.
    * @param target: Target number to find.
    * @return: The first position of target. Position starts from 0.
    */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int start = 0;
        int end = array.size();
        int tar = -1;

        while (start < end) {
            int pos = (start + end) / 2;
            if (array[pos] < target) {
                start = pos + 1;
            }
            else if (array[pos] > target) {
                end = pos;
            }
            else {
                tar = pos;
                end = pos;
            }
        }

        return tar;
    }
};
