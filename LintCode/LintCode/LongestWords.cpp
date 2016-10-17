#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
    * @param dictionary: a vector of strings
    * @return: a vector of strings
    */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> rs;
        int max_size = 0;
        for (int i = 0; i < dictionary.size(); i++) {
            if (dictionary[i].size() == max_size) {
                rs.push_back(dictionary[i]);
            }
            else if (dictionary[i].size() > max_size) {
                rs.clear();
                rs.push_back(dictionary[i]);
                max_size = dictionary[i].size();
            }
        }

        return rs;
    }
};
