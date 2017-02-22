#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param s: a string
	* @return: an integer
	*/
	int lengthOfLongestSubstring(string s) {
		// write your code here
		if (s.size() < 2) return s.size();
		int rs = 1;
		int start = 0;

		for (int i = 1; i < s.size(); i++) {
			int pos = -1;
			for (int j = start; j < i; j++) {
				if (s[j] == s[i]) {
					pos = j;
					break;
				}
			}
			if (pos == -1) {
				rs = max(rs, i - start + 1);
			}
			else {
				start = pos + 1;
			}
		}

		return rs;
	}
};
