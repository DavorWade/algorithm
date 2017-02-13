#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Solution {
public:
	/**
	* @param num a non-negative integer
	* @return one digit
	*/
	int addDigits(int num) {
		// Write your code here
		string str_num = to_string(num);

		while (str_num.size() > 1) {
			int new_num = 0;
			for (int i = 0; i < str_num.size(); i++) {
				new_num += str_num[i] - '0';
			}
			str_num = to_string(new_num);
		}

		return str_num[0] - '0';
	}
};
