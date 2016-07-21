#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	/**
	*@param A: A positive integer which has N digits, A is a string.
	*@param k: Remove k digits.
	*@return: A string
	*@date: 2016-7-21
	*/
	string DeleteDigits(string A, int k) {
		// wirte your code here
		int count = A.size() - k;
		int start = 0;
		int startIndex = 0;
		int end = k;
		string rs = "";

		while (count > 0) {
			char tem = A[start];
			startIndex = start; // if testcase is increase like "123456", below code 'startIndex = start;' will never be excuted.
			for (; start <= end && end < A.size(); start++) {
				if (A[start] < tem) {
					tem = A[start];
					startIndex = start;
				}
			}

			rs += tem;
			start = startIndex + 1;
			end++;
			count--;
		}

		rs.erase(0, rs.find_first_not_of("0")); //remove the charactor '0' in the front of rs.
		return rs;
	}
};

int main(int argc, char *argv[]){
	Solution s;
	string rs = s.DeleteDigits("123456789", 2);

	cout << "rs:" << rs << endl;

	system("pause");
	return 0;
}