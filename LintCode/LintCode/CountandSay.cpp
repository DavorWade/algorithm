#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
    * @param n the nth
    * @return the nth sequence
    */
    string countAndSay(int n) {
        // Write your code here
        vector<string> memory;
        if (n < 1) return "";
        if (n == 1) return "1";
        memory.push_back("1");
        memory.push_back("11");

        string rs = dfs(memory, n);

        return rs;
    }

    string dfs(vector<string> &memory, int n) {
        if (n <= memory.size()) return memory[n - 1];

        string prev = dfs(memory, n - 1);
        string rs;
        int count = 1;
        for (int i = 1; i < prev.size(); i++) {
            if (prev[i - 1] == prev[i]) {
                count++;
            }
            else {
                rs = rs + to_string(count) + prev[i - 1];
                count = 1;
            }
        }
        rs = rs + to_string(count) + prev[prev.size() - 1];
        memory.push_back(rs);

        return rs;
    }
};
