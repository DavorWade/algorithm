#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    /**
    *@param num: A list of non negative integers
    *@return: A string
    *@date: 2016-11-3
    */
    string largestNumber(vector<int> &num) {
        // write your code here
        string rs = "";
        set<pair<string, int> > table;
        set<pair<string, int> >::reverse_iterator it;

        int max_val = findMax(num);
        int num_count = numCount(max_val);

        for (int i = 0; i < num.size(); i++) {
            int curr_count = numCount(num[i]);
            string curr = to_string(num[i]);
            for (int j = 0; j < num_count - curr_count; j++) {
                // not "curr += '0';" or else, must use bellow 
                curr += to_string(num[i]);
            }
            pair<string, int> curr_pair = make_pair(curr, i);
            table.insert(curr_pair);
        }

        for (it = table.rbegin(); it != table.rend(); it++) {
            rs += to_string(num[it->second]);
        }
        if (rs[0] == '0') rs = "0";

        return rs;
    }

    int findMax(vector<int> &num) {
        int max_value = num[0];
        for (int i = 1; i < num.size(); i++) {
            if (max_value < num[i]) {
                max_value = num[i];
            }
        }

        return max_value;
    }

    int numCount(int val) {
        int num_count = 1;
        while (val >= 10) {
            num_count++;
            val = val / 10;
        }
        return num_count;
    }
};