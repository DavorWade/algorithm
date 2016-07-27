#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

/*
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> dataSize;
	vector<int> memory(m, 0);
	int start = 0;
	int end = m - 1;
	int minData = 0;
	
	for (int i = 0; i < n; i++) {
		if (dataSize[i] <= end - start + 1) {
			for (int j = start; j < end; j++) {
				memory[j] = i + 1;
			}
			start += dataSize[i];
		}
		else {
			while (dataSize[i] > end - start + 1) {
				for (int k = 0; k < memory.size(); i++) {
					if (memory[k] == minData) memory[k] = 0;
				}
			}
		}
	}

	system("pause");
	return 0;
}
*/