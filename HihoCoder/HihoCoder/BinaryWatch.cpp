#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <set>
#include <iostream>

using namespace std;
/*
Consider a binary watch with 5 binary digits to display hours (00 - 23) and 6 binary digits to display minutes (00 - 59).

For example 11:26 is displayed as 01011:011010.

Given a number x, output all times in human-readable format "hh:mm" when exactly x digits are 1.

 ‰»Î
An integer x. (0 °‹ x °‹ 9)

 ‰≥ˆ
All times in increasing order.
*/
set<string> rs;
string hour = "10111";
string minite = "111011";
string maxTime = "10111111011";
bool getTime(int x, int oneCount, int index, string time, set<string> &rs) {
	string tem = time;
	if (oneCount == x) {
		if (time <= maxTime) {
			rs.insert(time);
			return true;
		}
		return false;
	}

	getTime(x, oneCount, index + 1, tem, rs);

	tem[index] = '1';
	getTime(x, oneCount + 1, index + 1, tem, rs);
}

int main(){
	string time = "00000000000";
	int x;
	scanf("%d", &x);
	if (x == 0) {
		printf("00:00\n");
		return 0;
	}
	//int right = x < 6 ? x : 5;
	//int left = x - right;
	//int n = right;

	getTime(x, 0, 0, time, rs);
	
	for (set<string>::iterator it = rs.begin(); it != rs.end(); it++) {
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
