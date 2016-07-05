#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>

using namespace std;

map<string, int> rs;

void processCode(char *s, map<string, int> &rs) {
	string decode;

	for (unsigned int i = 0; i < strlen(s); i++) {
		if (decode.length() == 3) {
			decode += '-';
		}
		if (s[i] != '-') {
			if (int(s[i] - 'A') < 0) { //s[i] = '0'...'9'
				decode += s[i];
			}
			else { //s[i] = 'A'...'Z'
				int a;
				if (s[i] > 'P') {
					a = int((s[i] - 'B')) / 3 + 2;
				}
				else {
					a = int((s[i] - 'A')) / 3 + 2;
				}
				char *tem = (char*)malloc(sizeof(char));
				sprintf(tem, "%d", a);
				decode += tem;
			}
		}
	}

	//cout << "The decode is:" << decode << endl;
	map<string, int>::iterator it = rs.find(decode);
	if (it != rs.end()) {
		it->second++;
	}
	else {
		rs.insert(pair<string, int>(decode, 1));
	}
}

void printRs(map<string, int> &rs) {
	map<string, int>::iterator it;
	for (it = rs.begin(); it != rs.end(); it++) {
		if (it->second > 1) cout << it->first << " " << it->second << endl;
	}
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	char *code = (char *)malloc(sizeof(char) * 16);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", code);
		processCode(code, rs);
	}
	
	printRs(rs);

	system("pause");
	return 0;
}