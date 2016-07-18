#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string url;
	bool isCached = false;
	int currPos = 0;
	int n, m;
	cin >> n >> m;
	getchar();
	vector<string> cache(m, "");
	vector<int> urlCount(m, 0);

	for (int i = 0; i < n; i++) {
		getline(cin, url);
		//cout << "url:" << url << endl;

		for (int j = 0; j < m; j++) {
			if (cache[j] == url) {
				urlCount[j] += 1;
				isCached = true;
				printf("Cache\n");
			}
		}
		if (!isCached) {
			if (currPos >= m) {
				int leastUsed = urlCount[0];
				int leastUsedIndex = 0;
				for (int j = 1; j < m; j++) {
					if (leastUsed > urlCount[j]) {
						leastUsed = urlCount[j];
						leastUsedIndex = j;
					}
				}

				cache[leastUsedIndex] = url;
				urlCount[leastUsedIndex] = 1;
				printf("Internet\n");
			}
			else {
				cache[currPos] = url;
				urlCount[currPos] = 1;
				currPos++;
				printf("Internet\n");
			}
		}
		isCached = false;
	}

	system("pause");
	return 0;
}
