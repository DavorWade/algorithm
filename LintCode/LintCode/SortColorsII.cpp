#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param colors: A list of integer
	* @param k: An integer
	* @return: nothing
	*/
	void sortColors2(vector<int> &colors, int k) {
		// write your code here
		int pl = 0;
		int pr = colors.size() - 1;
		int i = 0;
		int min = 1, max = k;

		while (min < max) {
			while (i <= pr) {
				if (colors[i] == min) {
					swap(colors[pl], colors[i]);
					i++;
					pl++;
				}
				else if (colors[i] == max) {
					swap(colors[pr], colors[i]);
					pr--;
				}
				else {
					i++;
				}
			}
			i = pl;
			min++;
			max--;
		}
	}
};
