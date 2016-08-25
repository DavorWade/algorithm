#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    /**
    * @param digits A digital string
    * @return all posible letter combinations
    */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        vector<string> rs;
        if (digits.length() < 1) return rs;

        map<char, vector<char> > mapping;
        init(mapping);

        string temRs = "";
        //temRs += mapping[digits[0]][0];
        dfs(rs, temRs, mapping, 0, digits);

        return rs;
    }

    void init(map<char, vector<char> > &mapping) {
        mapping['2'] = { 'a', 'b', 'c' };
        mapping['3'] = { 'd', 'e', 'f' };
        mapping['4'] = { 'g', 'h', 'i' };
        mapping['5'] = { 'j', 'k', 'l' };
        mapping['6'] = { 'm', 'n', 'o' };
        mapping['7'] = { 'p', 'q', 'r', 's' };
        mapping['8'] = { 't', 'u', 'v' };
        mapping['9'] = { 'w', 'x', 'y', 'z' };
    }

    void dfs(vector<string> &rs, string temRs, map<char, vector<char> > &mapping, int n, string digits) {
        if (n == digits.length()) rs.push_back(temRs);

        for (int i = 0; i < mapping[digits[n]].size(); i++) {
            dfs(rs, temRs + mapping[digits[n]][i], mapping, n + 1, digits);
        }
    }
};