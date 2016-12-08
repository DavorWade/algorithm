#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
    * @param n an integer
    * @return true if this is a happy number or false
    */
    bool isHappy(int n) {
        // Write your code here
        if (n == 1) return true;
        std::vector<int> record;
        record.push_back(n);
        string str = to_string(n);
        long long total_sum = 0;

        while (total_sum != 1) {
            total_sum = 0;
            for (auto element : str) {
                int i = element - '0';
                total_sum += pow(i, 2);
            }

            if (find(record.begin(), record.end(), total_sum) != record.end()) {
                return false;
            }
            else {
                record.push_back(total_sum);
                str = to_string(total_sum);
            }
        }

        return true;
    }
};