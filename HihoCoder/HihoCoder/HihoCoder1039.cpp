#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @DATE: 2016-7-24
 */
int solve(string data, vector<string> charactor) {
	int rs = 0;
	int start = 0;
	int end = 0;

	for (unsigned int i = 0; i < charactor.size(); i++) {
		for (unsigned int j = 0; j <= data.size(); j++) {
			bool isIterateAgain = false;
			int count = 0;
			string tem = data;
			tem = tem.insert(j, charactor[i]);

			do {
				isIterateAgain = false;
				start = 0;
				end = 0;
				//cout << "tem:" << tem << endl;
				for (unsigned int k = 0; k < tem.size() - 1;) {
					if (tem[k] == tem[k + 1]) {
						end = k + 1;
						k++;
						isIterateAgain = true;
					}
					else{
						if (end > start) {
							tem.erase(start, end - start + 1);
							count += end - start + 1;

							k = start;
							end = start;
						}
						else {
							k++;
							start = k;
							end = start;

						}
					}
				}
				if (end > start && end < tem.size()) {
					tem.erase(start, end - start + 1);
					count += end - start + 1;
					
					if (tem.empty()) isIterateAgain = false;
				}
			} while (isIterateAgain);

			//cout << "count:" << count << endl;
			rs = max(rs, count);
		}
	}

	return rs;
}

/*
int main() {
	vector<string> charactor;
	charactor.push_back("A");
	charactor.push_back("B");
	charactor.push_back("C");
	int n;
	scanf("%d", &n);

	while (n--) {
		string data;
		cin >> data;

		int count = solve(data, charactor);
		printf("%d\n", count);
	}

	system("pause");
	return 0;
}
*/