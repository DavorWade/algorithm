#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>
#include <locale>
#include <algorithm>

using namespace std;

class Sentence {
private:
	vector<string> &split(const string &s, char delim, vector<string> &elems) {
		stringstream ss(s);
		string item;
		while (getline(ss, item, delim)) {
			elems.push_back(item);
		}
		return elems;
	}

	vector<string> split(const string &s, char delim) {
		vector<string> elems;
		split(s, delim, elems);
		return elems;
	}

public:
	string process(const string s) {
		string originSen;
		bool isCapital = false;
		vector<string> rs;
		char delim = ' ';

		rs = split(s, delim);

		for (int i = 0; i < rs.size(); i++) {
			if (rs[i] != "") {
				if (rs[i] == ","){
					originSen.append(",");
				}
				else if (rs[i] == "."){
					originSen.append(". ");
					isCapital = true;
				}
				else {
					transform(rs[i].begin(), rs[i].end(), rs[i].begin(), ::tolower);
					if (isCapital || i == 0) {
						locale loc;
						rs[i][0] = toupper(rs[i][0], loc);
						originSen.append(rs[i]);
					}
					else {
						originSen.append(" ");
						originSen.append(rs[i]);
					}
				}
			}
		}

		return originSen;
	}

};


int main() {
	vector<string> data;
	string tem;
	Sentence s;

	getline(cin, tem);
	while (tem != "") {
		data.push_back(tem);
		getline(cin, tem);
	}

	for (int i = 0; i < data.size(); i++) {
		string rs = s.process(data[i]);
		cout << rs << endl;
	}

	return 0;
}