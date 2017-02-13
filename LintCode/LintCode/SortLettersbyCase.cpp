#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param chars: The letters array you should sort.
	*/
	void sortLetters(string &letters) {
		// write your code here
		int l = 0;
		int r = letters.size() - 1;

		while (l < r) {
			while ('a' <= letters[l] && letters[l] <= 'z') l++;
			while ('A' <= letters[r] && letters[r] <= 'Z') r--;

			if (l < r) {
				char tmp = letters[l];
				letters[l] = letters[r];
				letters[r] = tmp;
				l++;
				r--;
			}
		}
	}
};
