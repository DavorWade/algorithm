#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
    * @param nums: A list of integers
    * @param k: As described
    * @return: The majority number
    */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> rs;
        unordered_map<int, int>::iterator it;
        int max_count = 0;
        int target;

        for (auto a : nums) {
            it = rs.find(a);
            if (it != rs.end()) {
                it->second++;
            }
            else {
                rs[a] = 1;
                if (rs.size() == k) {
                    for (it = rs.begin(); it != rs.end();) {
                        if (--(it->second) == 0) {
                            it = rs.erase(it);
                        }
                        else {
                            it++;
                        }
                    }
                }
            }
        }

        for (it = rs.begin(); it != rs.end(); it++) {
            it->second = 0;
        }

        for (auto val : nums) {
            it = rs.find(val);
            if (it != rs.end()) {
                it->second++;
            }
        }

        for (it = rs.begin(); it != rs.end(); it++) {
            if (it->second > max_count) {
                max_count = it->second;
                target = it->first;
            }
        }

        return target;
    }
};
