#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    /**
    * @param gas: a vector of integers
    * @param cost: a vector of integers
    * @return: an integer
    */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        int left = 0;
        int index = -1;
        for (int i = 0; i < gas.size(); i++) {
            int single_left = gas[i] - cost[i];
            left += single_left;
            if (single_left < 0 && left < 0) index = -1;
            else if (single_left >= 0 && index == -1) index = i;
        }
        if (left < 0) index = -1;

        return index;
    }
};
