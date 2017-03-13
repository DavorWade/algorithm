#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//https://hihocoder.com/problemset/problem/1272

void getLargest(vector<pair<int, int> > &val);

int main() {
	int Q, N;
	scanf("%d", &Q);

	for (int i = 0; i < Q; i++) {
		scanf("%d", &N);

		float a;
		int b;
		vector<pair<int, int> > val;

		for (int j = 0; j < N; j++) {
			scanf("%f %d", &a, &b);

			val.push_back(make_pair(b, int(a*10+0.0000001)));
		}
		sort(val.begin(), val.end(), greater<pair<int, int>>());

		getLargest(val);
	}

	system("pause");
	return 0;
}

void getLargest(vector<pair<int, int> > &val) {
	int max_val = 0;
	bool isBreak = false;

	for (unsigned int i = 0; i < val.size(); i++) {
		for (unsigned int j = i + 1; j < val.size(); j++) {
			for (unsigned int k = j + 1; k < val.size(); k++) {
				if (k == j + 1) {
					if (max_val >= val[i].first + val[j].first + val[k].first) {
						isBreak = true;
						break;
					}
				}

				int cost = val[i].second + val[j].second + val[k].second;
				if (max_val < val[i].first + val[j].first + val[k].first) {
					if (!(cost % 50)) {
						max_val = val[i].first + val[j].first + val[k].first;
					}
				}
			 }

			if (isBreak) break;
		}
		if (isBreak) break;
	}

	printf("%d\n", max_val);
}
