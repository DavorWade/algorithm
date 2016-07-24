#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<string, string> P;
set<P> rs;

/*
int main() {
	vector<vector<string> > data;
	vector<int> mList;
	int base = 0;
	int count = 1;
	int nn;
	int n;
	scanf("%d", &n);
	nn = n;
	
	while (n--) {
		int m;
		string id, date, price;

		scanf("%d", &m);
		mList.push_back(m);
		for (int i = 0; i < m; i++) {
			vector<string> tem;
			cin >> id >> date >> price;

			tem.push_back(id);
			tem.push_back(price);
			data.push_back(tem);
		}
	}

	base = mList[0];
	int k = 1;
	for (int i = 0; i < mList[0]; i++) {
		for (int j = base; j < data.size() && k < nn && j < base + mList[k];) {
			vector<string>::iterator it = find(data[j].begin(), data[j].end(), data[i][0]);
			if (it != data[j].end() && data[i][1] == data[j][1]){
				count++; 

				//printf("j:%d\n", j);
				base += mList[k++];
				j = base;
				//printf("base:%d\n", base);
			}
			else if (j == base + mList[k] - 1){
				break;
			}
			else {
				j++;
			}
		}

		//printf("count:%d\n", count);
		if (count == nn) {
			P p = make_pair(data[i][0], data[i][1]);
			//cout << "data[i][0]" << data[i][0] << endl;
			rs.insert(p);
		}
		count = 1;
		base = mList[0];
		k = 1;
	}

	for (set<P>::iterator it = rs.begin(); it != rs.end(); it++) {
		cout << it->first << endl;
	}

	system("pause");
	return 0;
}
*/