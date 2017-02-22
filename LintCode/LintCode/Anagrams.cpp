#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	/**
	* @param strs: A list of strings
	* @return: A list of strings
	*/
	vector<string> anagrams(vector<string> &strs) {
		// write your code here
		vector<string> rs;
		vector<bool> used(strs.size(), false);
		map<string, int> hash_map;
		map<string, int>::iterator it;

		for (int i = 0; i < strs.size(); i++) {
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());

			it = hash_map.find(tmp);
			if (it != hash_map.end()) {
				rs.push_back(strs[i]);
				used[i] = true;
				if (!used[it->second]) {
					rs.push_back(strs[it->second]);
					used[it->second] = true;
				}
			}
			else {
				hash_map[tmp] = i;
			}
		}

		return rs;
	}
};
