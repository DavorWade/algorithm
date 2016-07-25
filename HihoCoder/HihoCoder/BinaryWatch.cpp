#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> getCombinations(int n, int r) {
	vector<string> combination;
	vector<bool> v(n);
	fill(v.begin(), v.begin() + r, true);

	do {
		string tem;
		for (int i = 0; i < n; ++i) {
			if (v[i]) {
				tem += to_string(i);
			}
		}
		if (tem != "") combination.push_back(tem);
	} while (prev_permutation(v.begin(), v.end()));

	return combination;
}

vector<int> processTime(vector<string> &time, int maxTime) {
	vector<int> timeList;
	for (int i = 0; i < time.size(); i++) {
		string tem = time[i];
		int humanTime = 0;

		for (int j = 0; j < tem.length(); j++) {
			int n = tem[j] - '0';
			humanTime += pow(2, n);
		}
		if (humanTime < maxTime) timeList.push_back(humanTime);
	}
	return timeList;
}

/*
int main(){
	set<string> rs;
	int x;
	scanf("%d", &x);
	if (x == 0) {
		printf("00:00\n");
		return 0;
	}
	int right = x < 6 ? x : 5;
	int left = max(0, x - right);
	int n = right;

	while (right >= 0 && left < 5) {
		vector<string> r;
		vector<string> l;
		r = getCombinations(6, right);
		l = getCombinations(5, left);
		vector<int> rr = processTime(r, 60);
		vector<int> ll = processTime(l, 24);
		
		if (ll.empty()) {
			for (int i = 0; i < rr.size(); i++) {
				string tem = "";
				tem += "00:";
				if (rr[i] < 10) tem += "0";
				tem += to_string(rr[i]);
				rs.insert(tem);
			}
		}
		else if (rr.empty()) {
			for (int i = 0; i < ll.size(); i++) {
				string tem = "";
				if (ll[i] < 10) tem += "0";
				tem += to_string(ll[i]);
				tem += ":00";
				rs.insert(tem);
			}
		}
		else {
			for (int i = 0; i < ll.size(); i++) {
				for (int j = 0; j < rr.size(); j++) {
					string tem = "";
					if (ll[i] < 10) tem += "0";
					tem += to_string(ll[i]);
					tem += ":";

					if (rr[j] < 10) tem += "0";
					tem += to_string(rr[j]);
					rs.insert(tem);
				}
			}
		}

		right--;
		left++;
	}

	for (set<string>::iterator it = rs.begin(); it != rs.end(); it++) {
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
*/
